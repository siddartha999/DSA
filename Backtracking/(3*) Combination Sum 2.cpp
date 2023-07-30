/**
* Problem Link: https://leetcode.com/problems/combination-sum-ii/description/
* TC: O(2^ N); SC: O(2^ N * N)
**/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(0, nums, target, res, {});
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
            if(i > idx && nums[i] == nums[i - 1]) continue;
            row.push_back(nums[i]);
            helper(i + 1, nums, target - nums[i], res, row);
            row.pop_back();
        }
    }
};
