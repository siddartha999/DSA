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

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        string rootPreorder = "";
        serialize(root, rootPreorder);
        string subRootPreorder = "";
        serialize(subRoot, subRootPreorder);
        return kmp(rootPreorder, subRootPreorder);
    }

private:
    void serialize(TreeNode* root, string& str) {
        if(!root) {
            str += "#";
            return;
        }
        str += "<"; //Indicates the beginning of a root
        str += to_string(root->val);
        serialize(root->left, str);
        serialize(root->right, str);
        str += ">"; //Indicates the end of a root
    }

private:
    bool kmp(string haystack, string needle) {
        vector<int> lps = populateBoundary(needle);
        int idx = 0;
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[idx]) idx++;
            else {
                while(idx > 0) {
                    idx = lps[idx - 1];
                    if(haystack[i] == needle[idx]) {
                        idx++;
                        break;
                    }
                }
            }
            if(idx >= needle.size()) return true;
        }
        return false;
    }

private:
    vector<int> populateBoundary(string needle) {
        vector<int> lps(needle.size(), 0);
        int prev = 0, idx = 1;
        while(idx < needle.size()) {
            if(needle[idx] == needle[prev]) {
                lps[idx++] = ++prev;
            }
            else {
                if(prev > 0) prev = lps[prev - 1];
                else idx++;
            }
        }
        return lps;
    }
};
