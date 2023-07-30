/**
* Problem Link: https://leetcode.com/problems/subsets/
* TC: O(2^N); SC: O(2^N * N)
**/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, res, {});
        return res;
    }
private:
    void helper(int idx, vector<int>& nums, vector<vector<int>>& res, vector<int> row) {
        res.push_back(row);
        for(int i = idx; i < nums.size(); i++) {
            row.push_back(nums[i]);
            helper(i + 1, nums, res, row);
            row.pop_back();
        }
    }
};
