/**
* Problem link: https://leetcode.com/problems/subtree-of-another-tree/description/
*/


// Approach 1 Brute force => TC: O(MN), SC: O(M + N)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        return helper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        return root->val == subRoot->val && helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
    }
};



// Approach 2 KMP => TC: O(M + N), SC: O(M + N)
// The crucial part is the serialize(). Separating out subtrees properly is the central piece of this problem
// Without including NULLs none of the traversals(Pre, In, Post) & their combination would produce a unique sequence
// Preorder makes sense for serialize(), as for KMP it should be intuivite to trace a string from (left to right) :=> a tree from (root -> left ->right)
// Inorder would not produce a unique sequence even when NULLs are included
// Post order would produce as it is a reverse of pre-order, but intuitively, for this problem, does not make sense
// Ref: https://stackoverflow.com/questions/45871284/uniqueness-of-inorder-preorder-and-postorder-traversal-with-null-elements
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        string rootPreOrder = serialize(root);
        string subRootPreOrder = serialize(subRoot);
        return kmp(rootPreOrder, subRootPreOrder);
    }
private:
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string str = "<"; //Indicates the beginning of a root
        str += to_string(root->val);
        str += serialize(root->left);
        str += serialize(root->right);
        str += ">"; //Indicates the end of a root
        return str;
    }

    bool kmp(string haystack, string needle) {
        vector<int> lb = calculateBoundary(needle);
        int needleIdx = 0;
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[needleIdx]) needleIdx++;
            else {
                while(needleIdx > 0) {
                    needleIdx = lb[needleIdx - 1];
                    if(needle[needleIdx] == haystack[i]) {
                        needleIdx++;
                        break;
                    }
                }
            }
            if(needleIdx >= needle.size()) return true;
        }
        return false;
    }
    
    vector<int> calculateBoundary(string needle) {
        vector<int> lb(needle.size(), 0);
        int idx = 1; int prev = 0;
        while(idx < needle.size()) {
            if(needle[idx] == needle[prev]) {
                lb[idx++] = ++prev;
            }
            else {
                if(prev > 0) prev = lb[prev - 1];
                else idx++;
            }
        }
        return lb;
    }
};
