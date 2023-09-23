/**
* Problem Link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091
* Reference: https://www.youtube.com/watch?v=myPeWb3Y68A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21
**/

// Approach 1: Memoized. TC: O(N * Target), SC: O(N * Target) + O(N)
int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>> cache(num.size(), vector<int> (x + 1, -1));
    int res = helper(num, 0, x, cache);
    return res == INT_MAX ? -1 : res; 
}

int helper(vector<int>& nums, int idx, int target, vector<vector<int>>& cache) {
    if(target == 0) {
        return 0;
    }
    if(idx >= nums.size() || target < 0) {
        return INT_MAX;
    }

    if(cache[idx][target] != -1) return cache[idx][target];

    int repeat = helper(nums, idx, target - nums[idx], cache);
    int include = helper(nums, idx + 1, target - nums[idx], cache);
    int exclude =  helper(nums, idx + 1, target, cache);
    int minVal = min({repeat, include, exclude});
    cache[idx][target] = minVal + (minVal == exclude ? 0 : 1);

    return cache[idx][target];
}






//Approach 2: Tabulated. TC: O(N * Target), SC: O(N * Target)
int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>> cache(num.size() + 1, vector<int> (x + 1, INT_MAX));
    cache[num.size()][0] = 0;

    for(int idx = num.size() - 1; idx >= 0; idx--) {
        cache[idx][0] = 0;
        for(int target = 0; target <= x; target++) {
            int repeat = (target >= num[idx]) ? cache[idx][target - num[idx]] : INT_MAX;
            int exclude = cache[idx + 1][target];
            int minVal = min(repeat, exclude);
            cache[idx][target] = minVal + (minVal == exclude ? 0 : 1);
        }
    }

    return cache[0][x] == INT_MAX ? -1 : cache[0][x]; 
}







// Approach 3: Tabulated with Space Optimized. TC: O(N * Target), SC: O(Target)
int minimumElements(vector<int> &num, int x)
{
    vector<int> cache(x + 1, INT_MAX);
    cache[0] = 0;

    for(int idx = num.size() - 1; idx >= 0; idx--) {
        vector<int> temp = cache;
        for(int target = num[idx]; target <= x; target++) {
            int repeat = temp[target - num[idx]];
            int exclude = cache[target];
            int minVal = min({repeat, exclude});
            temp[target] = minVal + (minVal == exclude ? 0 : 1);
        }
        cache = temp;
    }

    return cache[x] == INT_MAX ? -1 : cache[x]; 
}
