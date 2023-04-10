/**
* Link: https://leetcode.com/problems/validate-binary-search-tree/description/
* NOTE: Prefer the iterative versions of Pre / In / Post order traversals
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;

        TreeNode* prev = NULL;
        stack<TreeNode*> stack;

        while(!stack.empty() || root) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(prev && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }

        return true;
    }
};


// TC: O(N), SC: O(N). O(N) complexity for BST in the worst case scenario i.e, a skewed BST
