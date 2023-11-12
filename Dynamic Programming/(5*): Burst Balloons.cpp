/**
* Problem Link: https://practice.geeksforgeeks.org/problems/maximum-number-of-coins--170647/1
* Reference: https://youtu.be/Yz4LlDSlkns?si=mTubA6TW3SKTgX2U
**/

// Approach 1: Brute Force. TC: Exponential, SC: O(N)
class Solution{
    public:
        int maxCoins(int N, vector <int> &nums)
        {
            nums.push_back(1);
            nums.insert(nums.begin(), 1);
            return helper(nums, 1, nums.size() - 2);
        }
    private:
        int helper(vector<int>& nums, int start, int end) {
            if(start > end) return 0;
            int maxVal = 0;
            for(int idx = start; idx <= end; idx++) {
                int val = (nums[idx] * nums[start - 1] * nums[end + 1]) + helper(nums, start, idx - 1) + helper(nums, idx + 1, end);
                maxVal = max(maxVal, val);
            }
            return maxVal;
        }
};




// Approach 2: Memoized. TC: O(N * N * N), SC: O(N * N * N). 
// Idea: Attack from the reverse to keep the sub-problems independent
class Solution{
    public:
        int maxCoins(int N, vector <int> &nums)
        {
            nums.push_back(1);
            nums.insert(nums.begin(), 1);
            vector<vector<int>> cache(nums.size(), vector<int> (nums.size(), -1));
            return helper(nums, 1, nums.size() - 2, cache);
        }
    private:
        int helper(vector<int>& nums, int start, int end, vector<vector<int>>& cache) {
            if(start > end) return 0;
            if(cache[start][end] != -1) return cache[start][end];
            int maxVal = 0;
            for(int idx = start; idx <= end; idx++) {
                int val = (nums[idx] * nums[start - 1] * nums[end + 1]) + helper(nums, start, idx - 1, cache) + helper(nums, idx + 1, end, cache);
                maxVal = max(maxVal, val);
            }
            cache[start][end] = maxVal;
            return maxVal;
        }
};




// Approach 3: TC: O(N * N * N), SC: O(N * N)
class Solution{
    public:
        int maxCoins(int N, vector <int> &nums)
        {
            nums.push_back(1);
            nums.insert(nums.begin(), 1);
            vector<vector<int>> cache(nums.size(), vector<int> (nums.size(), 0));
            for(int start = nums.size() - 2; start >= 1; start--) {
                for(int end = start; end <= nums.size() -2; end++) {
                    int maxVal = 0;
                    for(int idx = start; idx <= end; idx++) {
                        int val = (nums[idx] * nums[start - 1] * nums[end + 1]) + cache[start][idx - 1] + cache[idx + 1][end];
                        maxVal = max(maxVal, val);
                    }
                    cache[start][end] = maxVal;
                }
            }
            return cache[1][nums.size() - 2];
        }
};
