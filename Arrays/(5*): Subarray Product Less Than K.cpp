/**
* Link: https://leetcode.com/problems/subarray-product-less-than-k/description/
*/

// Approach 1: TC: O(N^2), SC: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int mod = 10e+7;
        for(int i = 0; i < nums.size(); i++) {
            long long prod = 1;
            for(int j = i; j < nums.size(); j++) {
                prod = (prod * nums[j]) % mod;
                if(prod < k) count++;
            }
        }
        return count;
    }
};



// Approach 2: TC:O(N), SC: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int left = 0, right = 0;
        long long prod = 1;
        while(right < nums.size()) {
            prod = prod * nums[right];
            while(left <= right && prod >= k) {
                prod /= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};
