/**
* Link: https://leetcode.com/problems/path-sum-ii/description/
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> row;
        if(!root) return res;
        helper(root, targetSum, res, row);
        return res;
    }

    void helper(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& row) {
        if(!root) return;
        row.push_back(root->val);
        if(!root->left && !root->right && root->val == target) {
            res.push_back(row);
        }
        helper(root->left, target - root->val, res, row);
        helper(root->right, target - root->val, res, row);
        row.pop_back();
    }
};

// TC: O(N), SC: O(H * K). Saved a bit of time & space by the handling of 'row' vector
