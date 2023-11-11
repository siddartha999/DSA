/**
* Problem Link: https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344
* Reference: https://youtu.be/pDCXsbAw5Cg?si=6XzZF12N_1nVBKRY
**/

// Approach 1: Memoized. TC: O(N * N * N), SC: O(N * N * N)
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> cache(N - 1, vector<int> (N, -1));
    return helper(arr, 1, N - 1, cache);
}

int helper(vector<int>& nums, int start, int end, vector<vector<int>>& cache) {
    if(start == end) return 0;
    if(cache[start][end] != -1) return cache[start][end];
    int minVal = INT_MAX;
    for(int temp = start; temp < end; temp++) {
        int val = (nums[start - 1] * nums[temp] * nums[end]) + helper(nums, start, temp, cache) + helper(nums, temp + 1, end, cache);
        minVal = min(minVal, val);
    }
    cache[start][end] = minVal;
    return minVal;
}


// Approach 2: Tabulated. TC: O(N * N * N), SC: O(N * N)
int matrixMultiplication(vector<int> &nums, int N)
{
    vector<vector<int>> cache(N, vector<int> (N + 1, 0));
    for(int start = N - 1; start >= 1; start--) {
        for(int end = start + 1; end < N; end++) {
            int minVal = INT_MAX;
            for(int temp = start; temp < end; temp++) {
                int val = (nums[start - 1] * nums[temp] * nums[end]) + cache[start][temp] + cache[temp + 1][end];
                minVal = min(minVal, val);
            }
            cache[start][end] = minVal;
        }
    }
    return cache[1][N - 1];
}
