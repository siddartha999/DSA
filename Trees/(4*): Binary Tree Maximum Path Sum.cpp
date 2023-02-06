/**
* Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
    int helper(TreeNode* root, int& maxSum) {
        if(!root) return 0;
        int leftMaxGain = max(helper(root->left, maxSum), 0);
        int rightMaxGain = max(helper(root->right, maxSum), 0);
        maxSum = max(maxSum, root->val + leftMaxGain + rightMaxGain);
        return root->val + max(leftMaxGain, rightMaxGain);
    }
};

// TC: O(N), SC: O(H) Auxilliary stack space
