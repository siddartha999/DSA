/**
A fun problem to solve!
Problem Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/
**/

// TC: O(nlogn), SC: O(1)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        int idx = 1;
        while(idx < nums.size()) {
            res = min(res + 1, nums[idx]);
            idx++;
        }
        return res;
    }
};
