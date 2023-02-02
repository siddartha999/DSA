/**
* Link: https://leetcode.com/problems/maximum-subarray/description/
* Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

// Approach 1: TC: O(N^2), SC: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            maxSum = max(maxSum, nums[i]);
            int currSum = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};

// Approach 2: Going Negative is a deal-breaker. TC: O(N), SC: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};
