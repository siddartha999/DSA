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



// Approach 2: Memoized. TC: O(N * N), SC: O(N * N) + O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> cache(nums.size() + 1, vector<int> (nums.size() + 2, -1));
        return helper(nums, 1, 0, cache);
    }
private:
    int helper(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& cache) {
        if(idx > nums.size()) return 0;

        if(cache[idx][prevIdx] != -1) return cache[idx][prevIdx];

        int pass = helper(nums, idx + 1, prevIdx, cache);
        int include = 0;
        if(prevIdx == 0 || nums[prevIdx - 1] < nums[idx - 1]) {
            include = 1 + helper(nums, idx + 1, idx, cache);
        }

        cache[idx][prevIdx] = max(pass, include);
        return cache[idx][prevIdx];
    }
};






// Approach 3: Tabulated. TC: O(N * N), SC: O(N * N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> cache(nums.size() + 2, vector<int> (nums.size() + 2, 0));
         
        for(int idx = nums.size(); idx > 0; idx--) {
            for(int prevIdx = 0; prevIdx < idx; prevIdx++) {
                int pass = cache[idx + 1][prevIdx];
                int include = 0;
                if(prevIdx == 0 || nums[prevIdx - 1] < nums[idx - 1]) {
                    include = 1 + cache[idx + 1][idx];
                }
                cache[idx][prevIdx] = max(pass, include);
            }
        }

        return cache[1][0];
    }
};
