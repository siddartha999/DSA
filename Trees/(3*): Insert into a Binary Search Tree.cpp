/**
* Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
*/

// Approach 1 => Recursive => TC: O(logN), SC: O(H)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }
        else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// Approach 2 => Iterative => TC: O(logN), SC: O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        while(temp) {
            prev = temp;
            if(temp->val > val) temp = temp->left;
            else temp = temp->right;
        }
        if(prev->val > val) prev->left = new TreeNode(val);
        else prev->right = new TreeNode(val);
        return root;
    }
};
