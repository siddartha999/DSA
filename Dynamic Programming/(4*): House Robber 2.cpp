/**
* Problem Link: https://leetcode.com/problems/house-robber-ii/description/
* Explanation Reference: https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7
*/

// TC: O(N), SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }

private:
    int helper(vector<int>& nums, int start, int end) {
        if(start == end) return nums[start];
        int rob1 = 0, rob2 = 0;
        for(int i = start; i <= end; i++) {
            int currMax = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = currMax;
        }
        return rob2;
    }
};

// For a single function call approach, 2D dp array has to be considered due to 2 variables: index & isFirstIndexIncluded
