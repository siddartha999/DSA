/**
* Problem Link: https://leetcode.com/problems/combination-sum/description/
* TC: O(2^target); SC: O(2^target * N)
**/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(0, candidates, target, res, {});
        return res;
    }

private:
    void helper(int idx, vector<int>& nums, int target, vector<vector<int>>& res, vector<int> row) {
        if(target == 0) {
            res.push_back(row);
            return;
        }
        if(target < 0) {
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            row.push_back(nums[i]);
            helper(i, nums, target - nums[i], res, row);
            row.pop_back();
        }
    }
};
