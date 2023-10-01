/**
* Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
**/


// Approach 1: Brute Force. TC: O(2^N), SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, 0, -1);
    }
private:
    int helper(vector<int>& nums, int idx, int prevIdx) {
        if(idx >= nums.size()) return 0;

        int pass = helper(nums, idx + 1, prevIdx);
        int include = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[idx]) {
            include = 1 + helper(nums, idx + 1, idx);
        }

        return max(pass, include);
    }
};
