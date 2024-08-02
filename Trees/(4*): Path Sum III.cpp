/**
* Link: https://leetcode.com/problems/path-sum-iii/description/
* Great explanation: https://leetcode.com/problems/path-sum-iii/solutions/141424/python-step-by-step-walk-through-easy-to-understand-two-solutions-comparison/
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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<int, int> cache;
        cache[0] = 1;
        helper(root, targetSum, 0, count, cache);
        return count;
    }

    void helper(TreeNode* root, int target, long long pathSum, int& count, unordered_map<int, int>& cache) {
        if(!root) return;
        pathSum = (pathSum + root->val) % 100000009;
        if(cache.find(pathSum - target) != cache.end()) count += cache[pathSum - target];
        cache[pathSum]++;
        helper(root->left, target, pathSum, count, cache);
        helper(root->right, target, pathSum, count, cache);
        cache[pathSum]--;
    }
};

// TC: O(N), SC: O(N) post the cache space optimization!
