/*
    Link to the problem: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
    You are given an array of integers nums and an integer target.
    Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 10^9 + 7.
*/

Solution:

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int total = 0;
        int mod = 1e9 + 7;
        vector<int> power(nums.size(), 1);
        for(int i = 1; i < power.size(); i++) power[i] = (power[i - 1] * 2) % mod;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int sum = nums[left] + nums[right];
            if(sum <= target) {
                total = (total + power[right - left]) % mod;
                left++;
            }
            else {
                right--;
            }
        }
        return total;
    }
};

/*
    TC: O(NlogN)
    SC: O(N) for storing the powers in cpp
    Inspired by: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/709227/java-c-python-two-sum/
    Notes: This can be solved as a regular susbequences backtracking porblem as well with a TC well over O(2^N)
*/    
