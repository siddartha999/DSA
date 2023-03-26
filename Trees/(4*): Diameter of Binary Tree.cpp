/**
* Link: https://leetcode.com/problems/diameter-of-binary-tree/description/
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

private:
    int helper(TreeNode* root, int& diameter) {
        if(!root) return 0;
        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
};


// TC: O(N), SC: O(H)
