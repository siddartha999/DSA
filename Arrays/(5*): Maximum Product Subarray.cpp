/**
* Link: https://leetcode.com/problems/maximum-product-subarray/description/
*/

// Approach 1: TC: O(N^2), SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int product = 1;
            for(int j = i; j < nums.size(); j++) {
                product *= nums[j];
                maxP = max(maxP, product);
            }
        }
        return maxP;
    }
};



// Approach 2: TC:O(N), SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int currMax = max({nums[i], maxSoFar * nums[i], minSoFar * nums[i]});
            int currMin = min({nums[i], maxSoFar * nums[i], minSoFar * nums[i]});
            maxSoFar = currMax;
            minSoFar = currMin;
            maxP = max(maxP, maxSoFar);
        }
        return maxP;
    }
};
