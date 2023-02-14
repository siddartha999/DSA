/**
Link: https://leetcode.com/problems/delete-node-in-a-bst/description/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // No children scenario
            if(!root->left && !root->right) return NULL;
            //1 child scenario
            if(!root->left || !root->right) {
                return root->left != NULL ? root->left : root->right;
            }
            // 2 children scenario
            TreeNode* left = root->left;
            while(left && left->right) left = left->right;
            root->val = left->val;
            root->left = deleteNode(root->left, left->val);
        }
        return root;
    }
};

// TC: O(N), SC: O(H)
