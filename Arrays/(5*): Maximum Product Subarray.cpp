/**
* Link: https://leetcode.com/problems/maximum-product-subarray/description/
*/

// Approach 1: Brute Force. TC: O(N^2), SC: O(1)
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





// Approach 2: a more natural optimization. TC: O(N), SC: O(N)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        int prod = 1;
        for(int idx = 0; idx < nums.size(); idx++) {
            prod *= nums[idx];
            prefix[idx] = prod;
            if(prod == 0) prod = 1;
        }
        prod = 1;
        for(int idx = nums.size() - 1; idx >= 0; idx--) {
            prod *= nums[idx];
            suffix[idx] = prod;
            if(prod == 0) prod = 1;
        }

        int maxProd = INT_MIN;
        for(int idx = 0; idx < nums.size(); idx++) {
            maxProd = max({maxProd, prefix[idx], suffix[idx]});
        }

        return maxProd;
    }
};





// Approach 3: TC:O(N), SC: O(1)
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
