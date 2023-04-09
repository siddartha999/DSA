/**
* Link: https://leetcode.com/problems/recover-binary-search-tree/description/
*/

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        inorderTraversal(root);
    }
private:
    void inorderTraversal(TreeNode* root) {
        TreeNode* first = NULL, *last = NULL, *prev = NULL;
        stack<TreeNode*> stack;
        while(root || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(prev != NULL) {
                if(prev->val > root->val) {
                    if(first == NULL) first = prev;
                    last = root;
                }
            }
            prev = root;
            root = root->right;
        }

        if(first && last) {
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
    }
};

// TC: O(N), SC: O(H). Go through a couple of examples to understand the significance of first & last pointers
