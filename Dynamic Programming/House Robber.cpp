/**
* Link: https://leetcode.com/problems/house-robber/description/
*/

//Step 1: TC: O(2^N), SC: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        return helper(nums, 0);
    }
private:
    int helper(vector<int>& nums, int idx) {
        if(idx >= nums.size()) return 0;
        int included = helper(nums, idx + 2) + nums[idx];
        int notIncluded = helper(nums, idx + 1);
        return max(included, notIncluded);
    }
};

//Step 2: TC:O(N), SC: O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> cache;
        return helper(nums, 0, cache);
    }
private:
    int helper(vector<int>& nums, int idx, unordered_map<int, int>& cache) {
        if(idx >= nums.size()) return 0;
        if(cache.find(idx) != cache.end()) return cache[idx];
        int included = helper(nums, idx + 2, cache) + nums[idx];
        int notIncluded = helper(nums, idx + 1, cache);
        cache[idx] = max(included, notIncluded);
        return cache[idx];
    }
};


//Step 3: Tabulation: TC: O(N), SC: O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[nums.size()];
    }
};


//Step 4: Space Optimization: TC: O(N), SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int prevIncluded = 0, prevNotIncluded = 0;
        for(int num: nums) {
            int currMax = max(prevNotIncluded + num, prevIncluded);
            prevNotIncluded = prevIncluded;
            prevIncluded = currMax;
        }
        return prevIncluded;
    }
};
