/*
  * Problem: https://leetcode.com/problems/combination-sum/description/
  * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen   numbers sum to target. You may return the combinations in any order.
*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(candidates, target, 0, {}, res);
        return res;
    }
    void helper(vector<int>& nums, int target, int idx, vector<int> row, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(row);
            return;
        }
        if(target < 0) {
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            row.push_back(nums[i]);
            helper(nums, target - nums[i], i, row, res);
            row.pop_back();
        }
    }
};

/*
  * TC: O((2^target) * k). k: average length of the row array
  * SC: O(k * t)
*/
