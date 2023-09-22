/**
* Problem Link: https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628
**/

// Approach 1: Brute Force. TC: O(2^N). SC: O(N).
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int num: arr) totalSum += num;
    if((d + totalSum) % 2 != 0) return 0;
    int target = (d + totalSum) / 2;
    return helper(arr, 0, target);
}


int helper(vector<int>& nums, int idx, int target) {
    if(idx >= nums.size()) {
        if(target == 0) return 1;
        return 0;
    }

    return helper(nums, idx + 1, target - nums[idx]) + helper(nums, idx + 1, target);    
}




// Approach 2: Memoized. TC: O(N * Target). SC:O(N * Target).
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int num: arr) totalSum += num;
    if((d + totalSum) % 2 != 0) return 0;
    int target = (d + totalSum) / 2;
    vector<vector<int>> cache(n + 1, vector<int> (target + 1, -1));
    return helper(arr, 0, target, cache);
}


int helper(vector<int>& nums, int idx, int target, vector<vector<int>>& cache) {
    if(idx >= nums.size()) {
        if(target == 0) return 1;
        return 0;
    }

    if(cache[idx][target] != -1) return cache[idx][target];

    int include = target - nums[idx] >= 0 ? helper(nums, idx + 1, target - nums[idx], cache) : 0;
    int notInclude = helper(nums, idx + 1, target, cache);
    cache[idx][target] = (include + notInclude) % 1000000007;

    return cache[idx][target];
}







// Appraoch 3: Tabulated. TC: O(N * Target), SC: O(N * Target).
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int num: arr) totalSum += num;
    if((d + totalSum) % 2 != 0) return 0;
    int target = (d + totalSum) / 2;
    vector<vector<int>> cache(n + 1, vector<int> (target + 1, 0));
    cache[n][0] = 1;
    
    for(int idx = n - 1; idx >= 0; idx--) {
        for(int currentTarget = 0; currentTarget <= target; currentTarget++) {
            int include = (currentTarget - arr[idx] >= 0) ? cache[idx + 1][currentTarget - arr[idx]] : 0;
            int notInclude = cache[idx + 1][currentTarget];
            cache[idx][currentTarget] = (include + notInclude) % 1000000007;
        }
    }
    
    return cache[0][target];
}








// Approach 4: Tabulated with Space Optimized. TC: O(N * Target), SC: O(Target).
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int num: arr) totalSum += num;
    if((d + totalSum) % 2 != 0) return 0;
    int target = (d + totalSum) / 2;
    vector<int> cache(target + 1, 0);
    cache[0] = 1;
    
    for(int idx = n - 1; idx >= 0; idx--) {
        vector<int> temp = cache;
        for(int currentTarget = 0; currentTarget <= target; currentTarget++) {
            int include = (currentTarget - arr[idx] >= 0) ? cache[currentTarget - arr[idx]] : 0;
            int notInclude = cache[currentTarget];
            temp[currentTarget] = (include + notInclude) % 1000000007;
        }
        cache = temp;
    }
    
    return cache[target];
}
