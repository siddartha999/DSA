/**
* Problem Link: https://www.codingninjas.com/studio/problems/selling-stock_630282
**/

// Approach 1: Brute Force. TC: O(2^N), SC: O(N)
long getMaximumProfit(long *values, int n)
{
    return helper(values, n, 0, true);
}

long helper(long* values, int& n, int idx, bool isBuy) {
    if(idx >= n) return 0;
    long res = 0;
    if(isBuy) {
        res = (-1 * values[idx]) + helper(values, n, idx + 1, false);
    }
    else {
        res = values[idx] + helper(values, n, idx + 1, true);
    }
    long pass = helper(values, n, idx + 1, isBuy);

    return max(res, pass);
}






// Approach 2: Memoized. TC: O(N * M), SC: O(N * M) + O(N + M)
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> cache(n, vector<long> (2, -1));
    return helper(values, n, 0, true, cache);
}

long helper(long* values, int& n, int idx, bool isBuy, vector<vector<long>>& cache) {
    if(idx >= n) return 0;

    if(cache[idx][isBuy] != -1) return cache[idx][isBuy];

    long res = 0;
    if(isBuy) {
        res = (-1 * values[idx]) + helper(values, n, idx + 1, false, cache);
    }
    else {
        res = values[idx] + helper(values, n, idx + 1, true, cache);
    }
    long pass = helper(values, n, idx + 1, isBuy, cache);

    cache[idx][isBuy] =  max(res, pass);
    return cache[idx][isBuy];
}







// Approach 3: Tabulated. TC: O(N * M), SC: O(N * M)
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> cache(n + 1, vector<long> (2, 0));


    for(int idx = n - 1; idx >= 0; idx--) {
        for(int j = 0; j <= 1; j++) {
            long res = 0;
            if(j == 0) {
                res = (-1 * values[idx]) + cache[idx + 1][1];
            }
            else {
                res = values[idx] + cache[idx + 1][0];
            }
            long pass = cache[idx + 1][j];
            cache[idx][j] = max(res, pass);
        }
    }

    return cache[0][0];
}







// Approach 4: Tabulated with Space Optimized. TC: O(N * M), SC: O(N)
long getMaximumProfit(long *values, int n)
{
    vector<long> cache(2, 0);

    for(int idx = n - 1; idx >= 0; idx--) {
        vector<long> temp = cache;
        for(int j = 0; j <= 1; j++) {
            long res = 0;
            if(j == 0) {
                res = (-1 * values[idx]) + cache[1];
            }
            else {
                res = values[idx] + cache[0];
            }
            long pass = cache[j];
            temp[j] = max(res, pass);
        }
        cache = temp;
    }

    return cache[0];
}
