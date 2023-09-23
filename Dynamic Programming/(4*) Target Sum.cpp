/**
* Problem Link: https://www.codingninjas.com/studio/problems/target-sum_4127362
* Reference: https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22
**/

// Appraoch 1: Memoized. TC: O(N * Target), SC: O(N * Target) + O(N).
int targetSum(int n, int target, vector<int>& arr) {
    vector<unordered_map<int, int>> cache(n);
    return helper(arr, 0, target, cache);
}

int helper(vector<int>& nums, int idx, int target, vector<unordered_map<int, int>>& cache) {
    if(idx >= nums.size()) {
        if(target == 0) return 1;
        return 0;
    }

    if(cache[idx].find(target) != cache[idx].end()) return cache[idx][target];

    int plus = helper(nums, idx + 1, target + nums[idx], cache);
    int minus = helper(nums, idx + 1, target - nums[idx], cache);

    cache[idx][target] = plus + minus;

    return cache[idx][target];
}





//Approach 2: Tabulated. TC: O(N * Target), SC: O(N * Target).
int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = 0;
    for(int num: arr) totalSum += num;

    if((totalSum + target) % 2 == 1) return 0;
    int firstSubsetSum = (totalSum + target) / 2;

    unordered_map<int, int> cache;
    cache[0] = 1;

    for(int idx = n - 1; idx >= 0; idx--) {
        unordered_map<int, int> temp = cache;
        for(int currentSum = -1000; currentSum <= firstSubsetSum; currentSum++) {
            int include = cache[currentSum - arr[idx]];
            int exclude = cache[currentSum];
            temp[currentSum] = include + exclude;
        }
        cache = temp;
    }

    return cache[firstSubsetSum];
}









//Appraoch 3: Tabulated with Space Optimized. TC: O(N * Target), SC: O(Target).
int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = 0;
    for(int num: arr) totalSum += num;
    int sum = totalSum - target;
    if(sum < 0 || (sum % 2 == 1)) return 0;
    int firstSubsetSum = (totalSum - target) / 2;

    vector<int> cache(firstSubsetSum + 1, 0);
    cache[0] = 1;

    for(int idx = n - 1; idx >= 0; idx--) {
        vector<int> temp = cache;
        temp[0] = 1;
        for(int currentSum = 1; currentSum <= firstSubsetSum; currentSum++) {
            int include = (currentSum - arr[idx] >= 0) ? 
                            cache[currentSum - arr[idx]] : 0;
            int exclude = cache[currentSum];
            temp[currentSum] = include + exclude;
        }
        cache = temp;
    }

    return cache[firstSubsetSum];
}
