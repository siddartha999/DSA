/**
* Problem Link: https://www.codingninjas.com/studio/problems/highway-billboards_3125969
**/

//Approach 1: Brute Force. TC: O(2^N), SC: O(N)
int stockProfit(vector<int> &prices){
    return helper(prices, 0, true);
}

int helper(vector<int>& prices, int idx, bool isBuy) {
    if(idx >= prices.size()) return 0;

    int indulge = 0;
    if(isBuy == true) {
        indulge = (-1 * prices[idx]) + helper(prices, idx + 1, false);
    }
    else {
        indulge = prices[idx] + helper(prices, idx + 2, true);
    }
    int pass = helper(prices, idx + 1, isBuy);
    
    return max(indulge, pass);
}






// Approach 2: Memoized. TC: O(N * 2), SC: O(N * 2) + O(N)
int stockProfit(vector<int> &prices){
    vector<vector<int>> cache(prices.size(), vector<int> (2, -1));
    return helper(prices, 0, true, cache);
}

int helper(vector<int>& prices, int idx, bool isBuy, vector<vector<int>>& cache) {
    if(idx >= prices.size()) return 0;

    if(cache[idx][isBuy] != -1) return cache[idx][isBuy];

    int indulge = 0;
    if(isBuy == true) {
        indulge = (-1 * prices[idx]) + helper(prices, idx + 1, false, cache);
    }
    else {
        indulge = prices[idx] + helper(prices, idx + 2, true, cache);
    }
    int pass = helper(prices, idx + 1, isBuy, cache);

    cache[idx][isBuy] = max(indulge, pass);
    return cache[idx][isBuy];
}










// Approach 3: Tabulated. TC: O(N * 2), SC: O(N * 2)
int stockProfit(vector<int> &prices){
    vector<vector<int>> cache(prices.size() + 2, vector<int> (2, 0));

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        for(int isBuy = 0; isBuy <= 1; isBuy++) {
            int indulge = 0;
            if(isBuy == 0) {
                indulge = (-1 * prices[idx]) + cache[idx + 1][1];
            }
            else {
                indulge = prices[idx] + cache[idx + 2][0];
            }
            int pass = cache[idx + 1][isBuy];
            cache[idx][isBuy] = max(indulge, pass);
        }
    }
    
    return cache[0][0];
}










// Approach 4: Tabulated with Space Optimized. TC: O(N * 2), SC: O(3 * 2)
int stockProfit(vector<int> &prices){
    vector<int> prevCache(2, 0);
    vector<int> cache(2, 0);

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        vector<int> temp = cache;
        for(int isBuy = 0; isBuy <= 1; isBuy++) {
            int indulge = 0;
            if(isBuy == 0) {
                indulge = (-1 * prices[idx]) + cache[1];
            }
            else {
                indulge = prices[idx] + prevCache[0];
            }
            int pass = cache[isBuy];
            temp[isBuy] = max(indulge, pass);
        }
        prevCache = cache;
        cache = temp;
    }
    
    return cache[0];
}
