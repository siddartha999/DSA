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


// Approach 2: The DP way: TC: O(N), SC: O(N). 
// Inspired by: https://leetcode.com/problems/maximum-subarray/solutions/20193/dp-solution-some-thoughts/?orderBy=most_votes

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        vector<int> dp(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            dp[i + 1] = (dp[i] < 0 ? 0 : dp[i]) + nums[i]; //If til prev subaryay is negative, the current should be a standalone subarray
            maxSum = max(maxSum, dp[i + 1]);
        }
        return maxSum;
    }
};


// Approach 3: Going Negative is a deal-breaker. TC: O(N), SC: O(1)

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
