/**
* Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
*/

// Approach 1: Populate inorder-traversal array. TC: O(N), SC: O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k == 0) return -1;
        vector<int> inorder = inorderTraversal(root);
        if(inorder.size() >= k) {
            return inorder[k - 1];
        }
        return -1;
    }
private:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        while(root || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};



// Approach 2 : Iterative inorder-traversal, early exit. TC: O(N), SC: O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k == 0) return -1;
        
        stack<TreeNode*> stack;
        while(root || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            k--;
            if(k == 0) return root->val;
            root = root->right;
        }

        return -1;
    }
};


// Approach 3: Recrusice, early exit. TC: O(N), SC: O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k == 0) return -1;
        TreeNode* found = NULL;
        helper(root, found, k);
        return found != NULL ? found->val : -1;
    }
private:
    void helper(TreeNode* root, TreeNode*& found, int& k) {
        if(!root || found) return;
        helper(root->left, found, k);
        k -= 1;
        if(k == 0) found = root;
        helper(root->right, found, k);
    }
};
