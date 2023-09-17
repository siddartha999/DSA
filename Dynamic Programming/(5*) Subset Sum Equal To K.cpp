/**
* Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
* Reference: https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15
**/



// Approach 1: Brute-Force. TC: O(2^N), SC: O(N)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return helper(arr, 0, n, k);
}

bool helper(vector<int>& nums, int idx, int& rows, int k) {
    if(k == 0) return true;
    if(idx >= rows) return false;

    bool include = helper(nums, idx + 1, rows, k - nums[idx]);
    bool notInclude = helper(nums, idx + 1, rows, k);

    return include || notInclude;
}





// Approach 2: Memoized. TC: O(N * Target), SC: O(N * Target)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> cache(n, vector<int> (k + 1, -1));
    return helper(arr, cache, 0, n, k);
}

bool helper(vector<int>& nums, vector<vector<int>>& cache, int idx, int& rows, int target) {
    if(target == 0) return true;
    if(idx >= rows || target < 0) return false;
    if(cache[idx][target] != -1) {
        return (cache[idx][target] == 1 ? true : false);
    }
    bool include = helper(nums, cache, idx + 1, rows, target - nums[idx]);
    if(include == true) {
        cache[idx][target] = 1;
        return true;
    }
    bool notInclude = helper(nums, cache, idx + 1, rows, target);
    cache[idx][target] = (notInclude == true ? 1 : 0);
    return notInclude;
}





// Approach 3: Tabulated. TC: O(N * Target), SC: O(N * Target)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> cache(n + 1, vector<int> (k + 1, 0));
    cache[n][0] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int target = 0; target <= k; target++) {
            if(target == 0) {
                 cache[i][target] = 1;
                 continue;
            }
            int include = (target - arr[i] >= 0) ? cache[i + 1][target - arr[i]] : 0;
            int notInclude = cache[i + 1][target];
            if(include == 1 || notInclude == 1) cache[i][target] = 1;
            else cache[i][target] = 0;
        }
    }

    return cache[0][k];
}





// Approach 4: Tabulated & Space optimized. TC: O(N * Target), SC: O(Target).

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> cache(k + 1, 0);
    cache[0] = 1;
    for(int i = n - 1; i >= 0; i--) {
        vector<int> temp = cache;
        for(int target = 0; target <= k; target++) {
            if(target == 0) {
                 temp[target] = 1;
                 continue;
            }
            int include = (target - arr[i] >= 0) ? cache[target - arr[i]] : 0;
            int notInclude = cache[target];
            if(include == 1 || notInclude == 1) temp[target] = 1;
            else temp[target] = 0;
        }
        cache = temp;
    }

    return cache[k];
}
