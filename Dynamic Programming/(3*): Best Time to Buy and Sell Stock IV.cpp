/**
* Problem Link: https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_1080698
**/

// Approach 1: Brute Force. TC: O(2^N * 2K), SC: O(N)
int maximumProfit(vector<int> &prices, int n, int k)
{
    return helper(prices, 0, k * 2);
}

int helper(vector<int>& prices, int idx, int k) {
    if(idx >= prices.size() || k == 0) return 0;
    
    int indulge = 0;
    if(k % 2 == 0) {
        indulge = (-1 * prices[idx]) + helper(prices, idx + 1, k - 1);
    }
    else {
        indulge = prices[idx] + helper(prices, idx + 1, k - 1);
    }
    int pass = helper(prices, idx + 1, k);

    return max(indulge, pass);
}





// Approach 2: Memoized. TC: O(N * 2 * K), SC: O(N * 2 * K) + O(N)
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> cache(prices.size(), vector<int> ((k * 2) + 1, -1));
    return helper(prices, 0, k * 2, cache);
}

int helper(vector<int>& prices, int idx, int k, vector<vector<int>>& cache) {
    if(idx >= prices.size() || k == 0) return 0;
    
    if(cache[idx][k] != -1) return cache[idx][k];

    int indulge = 0;
    if(k % 2 == 0) {
        indulge = (-1 * prices[idx]) + helper(prices, idx + 1, k - 1, cache);
    }
    else {
        indulge = prices[idx] + helper(prices, idx + 1, k - 1, cache);
    }
    int pass = helper(prices, idx + 1, k, cache);

    cache[idx][k] = max(indulge, pass);
    return cache[idx][k];
}







// Approach 3: Tabulated. TC: O(N * 2 * K), SC: O(N * 2 * K)
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> cache(prices.size() + 1, vector<int> ((k * 2) + 1, 0));

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        for(int transaction = 1; transaction <= (2 * k); transaction++) {
            int indulge = 0;
            if(transaction % 2 == 0) {
                indulge = (-1 * prices[idx]) + cache[idx + 1][transaction - 1];
            }
            else {
                indulge = prices[idx] + cache[idx + 1][transaction - 1];
            }
            int pass = cache[idx + 1][transaction];
            cache[idx][transaction] = max(indulge, pass);
        }
    }

    return cache[0][2 * k];
}







// Approach 4: Tabulated with Space Optimized 2D. TC: O(N * 2 * K), SC: O(2 * K * 2)
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> cache((k * 2) + 1, 0);

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        vector<int> temp = cache;
        for(int transaction = 1; transaction <= (2 * k); transaction++) {
            int indulge = 0;
            if(transaction % 2 == 0) {
                indulge = (-1 * prices[idx]) + cache[transaction - 1];
            }
            else {
                indulge = prices[idx] + cache[transaction - 1];
            }
            int pass = cache[transaction];
            temp[transaction] = max(indulge, pass);
        }
        cache = temp;
    }

    return cache[2 * k];
}






// Approach 5: Tabulated with Space Optimized 1D. TC: O(N * 2 * K), SC: O(2 * K)
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> cache((k * 2) + 1, 0);

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        //vector<int> temp = cache;
        for(int transaction = 2 * k; transaction >= 0; transaction--) {
            int indulge = 0;
            if(transaction % 2 == 0) {
                indulge = (-1 * prices[idx]) + cache[transaction - 1];
            }
            else {
                indulge = prices[idx] + cache[transaction - 1];
            }
            int pass = cache[transaction];
            cache[transaction] = max(indulge, pass);
        }
        //cache = temp;
    }

    return cache[2 * k];
}
