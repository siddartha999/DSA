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





// Approach 4: Tabulated with Space Optimized 2D. TC: O(N * N), SC: O(N * 2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache(nums.size() + 2, 0);
         
        for(int idx = nums.size(); idx > 0; idx--) {
            vector<int> temp = cache;
            for(int prevIdx = 0; prevIdx < idx; prevIdx++) {
                int pass = cache[prevIdx];
                int include = 0;
                if(prevIdx == 0 || nums[prevIdx - 1] < nums[idx - 1]) {
                    include = 1 + cache[idx];
                }
                temp[prevIdx] = max(pass, include);
            }
            cache = temp;
        }

        return cache[0];
    }
};






// Approach 5: Tabulated with Space Optimized 1D. TC: O(N * N), SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache(nums.size() + 2, 0);
         
        for(int idx = nums.size(); idx > 0; idx--) {
            for(int prevIdx = idx - 1; prevIdx >= 0; prevIdx--) {
                int pass = cache[prevIdx];
                int include = 0;
                if(prevIdx == 0 || nums[prevIdx - 1] < nums[idx - 1]) {
                    include = 1 + cache[idx];
                }
                cache[prevIdx] = max(pass, include);
            }
        }

        return cache[0];
    }
};




// Approach 6: Greedy (Does not give the exact LIS though). TC: O(NlogN), SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache;
        for(int num: nums) {
            if(cache.size() == 0 || cache[cache.size() - 1] < num) {
                cache.push_back(num);
            }
            else {
                int nextGreaterIdx = helper(cache, num);
                cache[nextGreaterIdx] = num;
            }
        }

        return cache.size();
    }
private:
    int helper(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
