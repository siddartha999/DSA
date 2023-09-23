/**
* Problem Link: https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471
**/

// Approach 1: Brute Force. TC: O(2^N * Target), SC: O(N).
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return helper(denominations, 0, n, value);
}

long helper(int* denominations, int idx, int rows, int target) {
    if(target == 0) return 1;
    if(target < 0 || idx >= rows) return 0;
    long include = helper(denominations, idx, rows, target - denominations[idx]);
    long exclude = helper(denominations, idx + 1, rows, target);
    return include + exclude;
}




// Approach 2: Memoized. TC: O(N * Target), SC: O(N * Target) +  O(N).
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> cache(n, vector<long>(value + 1, -1));
    return helper(denominations, 0, n, value, cache);
}

long helper(int* denominations, int idx, int rows, int target, vector<vector<long>>& cache) {
    if(target == 0) return 1;
    if(target < 0 || idx >= rows) return 0;
    if(cache[idx][target] != -1) return cache[idx][target];
    long include = helper(denominations, idx, rows, target - denominations[idx], cache);
    long exclude = helper(denominations, idx + 1, rows, target, cache);
    cache[idx][target] = include + exclude;
    return cache[idx][target];
}





//Approach 3: Tabulated. TC: O(N * Target), SC: O(N * Target).
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> cache(n + 1, vector<long>(value + 1, 0));
    cache[n][0] = 1;
    
    for(int idx = n - 1; idx >= 0; idx--) {
        cache[idx][0] = 1;
        for(int curr = 1; curr <= value; curr++) {
            long val = curr - denominations[idx];
            long include = (val >= 0) ? cache[idx][val] : 0;
            long exclude = cache[idx + 1][curr];
            cache[idx][curr] = include + exclude;
        }
    }

    return cache[0][value];
}








// Approach 4: Tabulated with Space Optimized. TC: O(N * Target), SC: O(Target).
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> cache(value + 1, 0);
    cache[0] = 1;
    
    for(int idx = n - 1; idx >= 0; idx--) {
        for(int curr = 1; curr <= value; curr++) {
            long val = curr - denominations[idx];
            long include = (val >= 0) ? cache[val] : 0;
            cache[curr] += include;
        }
    }

    return cache[value];
}
