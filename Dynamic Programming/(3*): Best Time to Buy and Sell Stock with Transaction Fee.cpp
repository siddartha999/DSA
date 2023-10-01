/**
* Problem Link: https://www.codingninjas.com/studio/problems/rahul-and-his-chocolates_3118974
**/

// Approach 1: Brute Force. TC: O(2^N), SC: O(N)
int maximumProfit(vector<int> &prices, int n, int fee)
{
	return helper(prices, 0, true, fee);
}

int helper(vector<int>& prices, int idx, bool isBuy, int& fee) {
	if(idx >= prices.size()) return 0;

	int indulge = 0;
	if(isBuy) {
		indulge = (-1 * prices[idx]) + helper(prices, idx + 1, false, fee);
	}
	else {
		indulge = prices[idx] - fee + helper(prices, idx + 1, true, fee);
	}
	int pass = helper(prices, idx + 1, isBuy, fee);

	return max(indulge, pass);
}






// Approach 2: Memoized. TC: O(N * 2), SC: O(N * 2) + O(N)
int maximumProfit(vector<int> &prices, int n, int fee)
{
	vector<vector<int>> cache(prices.size(), vector<int> (2, -1));
	return helper(prices, 0, true, fee, cache);
}

int helper(vector<int>& prices, int idx, bool isBuy, int& fee, vector<vector<int>>& cache) {
	if(idx >= prices.size()) return 0;

	if(cache[idx][isBuy] != -1) return cache[idx][isBuy];

	int indulge = 0;
	if(isBuy) {
		indulge = (-1 * prices[idx]) + helper(prices, idx + 1, false, fee, cache);
	}
	else {
		indulge = prices[idx] - fee + helper(prices, idx + 1, true, fee, cache);
	}
	int pass = helper(prices, idx + 1, isBuy, fee, cache);

	cache[idx][isBuy] = max(indulge, pass);
	return cache[idx][isBuy];
}








// Approach 3: Tabulated. TC: O(N * 2), SC: O(N * 2)
int maximumProfit(vector<int> &prices, int n, int fee)
{
	vector<vector<int>> cache(prices.size() + 1, vector<int> (2, 0));

	for(int idx = prices.size() - 1; idx >= 0; idx--) {
		
		//Buy Case
		cache[idx][0] = max( (-1 * prices[idx] + cache[idx + 1][1]), (cache[idx + 1][0]));

		//Sell Case
		cache[idx][1] = max( (prices[idx] - fee + cache[idx + 1][0]), (cache[idx + 1][1]));
	}

	return cache[0][0];
}








// Approach 4: Tabulated with Space Optimized. TC: O(N * 2), SC: O(4)
int maximumProfit(vector<int> &prices, int n, int fee)
{
	vector<int> cache(2, 0);

	for(int idx = prices.size() - 1; idx >= 0; idx--) {
		
		vector<int> temp = cache;
		
		//Buy Case
		temp[0] = max( (-1 * prices[idx] + cache[1]), (cache[0]));

		//Sell Case
		temp[1] = max( (prices[idx] - fee + cache[0]), (cache[1]));

		cache = temp;
	}

	return cache[0];
}
