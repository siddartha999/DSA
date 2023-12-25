/**
* Problem Link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/
**/

//Approach 1: Brute Force. TC:Exponential (my guess is O(K^N)). SC: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return helper(arr, k, 0);
    }
private:
    int helper(vector<int>& nums, int& k, int start) {
        if(start >= nums.size()) return 0;
        int maxVal = 0;
        int length = 1;
        int maxSum = 0;

        for(int idx = start; idx < start + k && idx < nums.size(); idx++) {
            maxVal = max(maxVal, nums[idx]);
            int sum = (maxVal * length) + helper(nums, k, idx + 1);
            maxSum = max(maxSum, sum);
            length++;
        }

        return maxSum;
    }
};


//Approach 2: Memoized. TC: O(N * K), SC: O(N) + O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> cache(arr.size(), -1);
        return helper(arr, k, 0, cache);
    }
private:
    int helper(vector<int>& nums, int& k, int start, vector<int>& cache) {
        if(start >= nums.size()) return 0;
        if(cache[start] != -1) return cache[start];
        int maxVal = 0;
        int length = 1;
        int maxSum = 0;

        for(int idx = start; idx < start + k && idx < nums.size(); idx++) {
            maxVal = max(maxVal, nums[idx]);
            int sum = (maxVal * length) + helper(nums, k, idx + 1, cache);
            maxSum = max(maxSum, sum);
            length++;
        }

        cache[start] = maxSum;
        return maxSum;
    }
};




// Approach 3: Tabulated. TC: O(N * K), SC: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> cache(arr.size() + 1, 0);

        for(int start = arr.size() - 1; start >= 0; start--) {
            int maxVal = 0;
            int length = 1;
            int maxSum = 0;
            for(int idx = start; idx < start + k && idx < arr.size(); idx++) {
                maxVal = max(maxVal, arr[idx]);
                int sum = (maxVal * length) + cache[idx + 1];
                maxSum = max(maxSum, sum);
                length++;
            }
            cache[start] = maxSum;
        }

        return cache[0];
    }
};
