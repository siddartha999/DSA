/**
Problem link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
**/

// TC: O(N), SC: O(H)
class Solution {
  public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode* res = NULL;
        int deepest = 0;
        helper(root, res, 1, deepest);
        return res;
    }
  private:
    int helper(TreeNode* root, TreeNode*& res, int level, int& deepest) {
        if(deepest < level) deepest = level;
        if(!root) return level;
        int leftDepth = helper(root->left, res, level + 1, deepest);
        int rightDepth = helper(root->right, res, level + 1, deepest);
        if(leftDepth == rightDepth && leftDepth == deepest) {
            res = root;
        }
        return max(leftDepth, rightDepth);
    }
};
