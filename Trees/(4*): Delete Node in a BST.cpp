/**
Link: https://leetcode.com/problems/delete-node-in-a-bst/description/
*/

// Approach 1: TC: O(logN), SC: O(logN)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(!root->left && !root->right) return NULL;
            if(!root->left || !root->right) return root->left == NULL ? root->right : root->left;
            TreeNode* temp = root->left;
            while(temp && temp->right) temp = temp->right;
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
        return root;
    }
};


// Approach 2: TC:O(logN), SC: O(1)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* node = root;
        TreeNode* prev = NULL;
        while(node && node->val != key) {
            prev = node;
            if(node->val > key) node = node->left;
            else if(node->val < key) node = node->right;
        }
        if(node != NULL && node->val == key) {
            if(!node->left && !node->right) { // 0 Children Case
                if(!prev) return NULL;
                if(prev->left == node) prev->left = NULL;
                else prev->right = NULL;
            }
            else if(!node->left || !node->right) { // 1 Child Case
                TreeNode* ret = node->left == NULL ? node->right : node->left;
                if(!prev) return ret;
                if(prev->left == node) prev->left = ret;
                else prev->right = ret;
            }
            else { // 2 Children Case
                TreeNode* temp = node->left;
                prev = node;
                while(temp && temp->right) {
                    prev = temp;
                    temp = temp->right;
                }
                if(prev != node) {
                    prev->right = temp->left;
                }
                else { //Edge Case
                    node->left = temp->left;
                }
                node->val = temp->val;
            }
        }
        
        return root;
    }
};
