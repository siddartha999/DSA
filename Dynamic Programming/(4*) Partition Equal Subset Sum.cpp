/**
* Problem link: https://leetcode.com/problems/partition-equal-subset-sum/description/
**/

// Approach 1. Brute Force. TC: O(2^N), SC: O(N)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;
        return helper(nums, 0, totalSum / 2);
    }

private: 
    bool helper(vector<int>& nums, int idx, int target) {
        if(target == 0) return true;
        if(target < 0 || idx >= nums.size()) return false;

        bool include = helper(nums, idx + 1, target - nums[idx]);
        bool notInclude = helper(nums, idx + 1, target);
        
        return include || notInclude;
    }
};





// Approach 2. Memoized. TC: O(N * Target), SC: (N * Target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<vector<int>> cache(nums.size(), vector<int> (target + 1, -1));
        return helper(nums, cache, 0, target);
    }

private: 
    bool helper(vector<int>& nums, vector<vector<int>>& cache, int idx, int target) {
        if(target == 0) return true;
        if(target < 0 || idx >= nums.size()) return false;
        if(cache[idx][target] != -1) return cache[idx][target];
        bool include = helper(nums, cache, idx + 1, target - nums[idx]);
        if(include == true) {
            cache[idx][target] = true;
            return true;
        }

        bool notInclude = helper(nums, cache, idx + 1, target);
        cache[idx][target] = notInclude;
        return notInclude;
    }
};






// Approach 3: Tabulated. TC: O(N * Target), SC: O(Target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<vector<bool>> cache(nums.size() + 1, vector<bool> (target + 1, false));
        cache[nums.size()][0] = true;


        for(int idx = nums.size() - 1; idx >= 0; idx--) {
            for(int currentTarget = 0; currentTarget <= target; currentTarget++) {
                if(currentTarget == 0) {
                    cache[idx][currentTarget] = true;
                }
                else {
                    bool include = currentTarget - nums[idx] >= 0 ? cache[idx + 1][currentTarget - nums[idx]] : false;
                    bool notInclude = cache[idx + 1][currentTarget];
                    cache[idx][currentTarget] = include || notInclude;
                }
            }
        }

        return cache[0][target];
    }
};







// Approach 4: Tabulated & Space optimized. TC: O(N * Target), SC: O(Target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) totalSum += num;
        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<bool> cache(target + 1, false);
        cache[0] = true;

        for(int idx = nums.size() - 1; idx >= 0; idx--) {
            vector<bool> temp = cache;
            for(int currentTarget = 0; currentTarget <= target; currentTarget++) {
                if(currentTarget == 0) {
                    temp[currentTarget] = true;
                }
                else {
                    bool include = currentTarget - nums[idx] >= 0 ? cache[currentTarget - nums[idx]] : false;
                    bool notInclude = cache[currentTarget];
                    temp[currentTarget] = include || notInclude;
                }
            }
            cache = temp;
        }

        return cache[target];
    }
};
