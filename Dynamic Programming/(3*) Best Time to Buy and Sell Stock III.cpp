/**
* Problem Link: https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012
**/

// Approach 1: Brute Force. TC: O(2^N), SC: O(N)
int maxProfit(vector<int>& prices)
{
    return helper(prices, 0, true, 2);
}

int helper(vector<int>& prices, int idx, bool isBuy, int stocks) {
    if(idx >= prices.size() || stocks == 0) return 0;
    
    int res = 0;
    if(isBuy) {
        res = (-1 * prices[idx]) + helper(prices, idx + 1, false, stocks);
    }
    else {
        res = prices[idx] + helper(prices, idx + 1, true, stocks - 1);
    }
    int pass = helper(prices, idx + 1, isBuy, stocks);

    return max(res, pass);
}







// Approach 2: Memoized. TC: O(N * 2 * 3), SC: O(N * 2 * 3)
int maxProfit(vector<int>& prices)
{
    vector<vector<vector<int>>> cache(prices.size(), vector<vector<int>> (2, vector<int> (3, -1)));
    return helper(prices, 0, true, 2, cache);
}

int helper(vector<int>& prices, int idx, bool isBuy, int stocks, vector<vector<vector<int>>>& cache) {
    if(idx >= prices.size() || stocks == 0) return 0;
    
    if(cache[idx][isBuy][stocks] != -1) return cache[idx][isBuy][stocks];

    int res = 0;
    if(isBuy) {
        res = (-1 * prices[idx]) + helper(prices, idx + 1, false, stocks, cache);
    }
    else {
        res = prices[idx] + helper(prices, idx + 1, true, stocks - 1, cache);
    }
    int pass = helper(prices, idx + 1, isBuy, stocks, cache);

    cache[idx][isBuy][stocks] =  max(res, pass);
    return cache[idx][isBuy][stocks];
}








// Approach 3: Tabulated. TC: O(N * 2 * 3), SC: O(N * 2 * 3)
int maxProfit(vector<int>& prices)
{
    vector<vector<vector<int>>> cache(prices.size() + 1, vector<vector<int>> (2, vector<int> (3, 0)));

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        for(int j = 0; j <=1 ; j++) {
            for(int stocks = 1; stocks <= 2; stocks++) {
                int res = 0;
                if(j == 0) {
                    res = (-1 * prices[idx]) + cache[idx + 1][1][stocks];
                }
                else {
                    res = prices[idx] + cache[idx + 1][0][stocks - 1];
                }
                int pass = cache[idx + 1][j][stocks];
                cache[idx][j][stocks] = max(res, pass);
            }
        }
    }

    return cache[0][0][2];
}









// Approach 4: Tabulated with Space Optimized 2D. TC: O(N * 2 * 3), SC: O(1)
int maxProfit(vector<int>& prices)
{
    vector<vector<int>> cache(2, vector<int> (3, 0));

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        vector<vector<int>> temp = cache;
        for(int j = 0; j <=1 ; j++) {
            for(int stocks = 1; stocks <= 2; stocks++) {
                int res = 0;
                if(j == 0) {
                    res = (-1 * prices[idx]) + cache[1][stocks];
                }
                else {
                    res = prices[idx] + cache[0][stocks - 1];
                }
                int pass = cache[j][stocks];
                temp[j][stocks] = max(res, pass);
            }
        }
        cache = temp;
    }

    return cache[0][2];
}




// Approach 5: Tabulated with Space Optimized 1D. TC: O(N * 4), SC: O(1)
int maxProfit(vector<int>& prices)
{
    vector<int> cache (5, 0);

    for(int idx = prices.size() - 1; idx >= 0; idx--) {
        vector<int> temp = cache;
        for(int j = 0; j <= 3; j++) {
            int res = 0;
            if(j % 2 == 0) {
                res = (-1 * prices[idx]) + cache[j + 1];
            }
            else {
                res = prices[idx] + cache[j + 1];
            }
            int pass = cache[j];
            temp[j] = max(res, pass);
        }
        cache = temp;
    }

    return cache[0];
}
