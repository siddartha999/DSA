/**
* Problem Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
* Reference: https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20
**/

// Appraoch 1: Memoized. TC: O(N * maxWeight), SC: O(N * maxWeight) + O(N: auxilliary stack)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> cache(n, vector<int> (maxWeight + 1, -1));
	return helper(weight, value, 0, maxWeight, cache);
}

int helper(vector<int>& weight, vector<int>& value, int idx, int maxWeight, vector<vector<int>>& cache) {
	if(idx >= weight.size()) {
		return 0;
	}

	if(cache[idx][maxWeight] != -1) return cache[idx][maxWeight];

	int include = 0;
	if(maxWeight - weight[idx] >= 0) {
		include = value[idx] + helper(weight, value, idx + 1, maxWeight - weight[idx], cache);
	}
	int exclude = helper(weight, value, idx + 1, maxWeight, cache);

	cache[idx][maxWeight] = max(include, exclude);

	return cache[idx][maxWeight];
}






// Appraoch 2: Tabulated. TC: O(N * maxWeight), SC: O(N * maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> cache(n + 1, vector<int> (maxWeight + 1, 0));
	
	for(int idx = n - 1; idx >= 0; idx--) {
		for(int currWeight = 0; currWeight <= maxWeight; currWeight++) {
			int include = 0;
			if(currWeight - weight[idx] >= 0) {
				include = value[idx] + cache[idx + 1][currWeight - weight[idx]];
			}
			int exclude = cache[idx + 1][currWeight];
			cache[idx][currWeight] = max(include, exclude);
		}
	}

	return cache[0][maxWeight];
}








// Approach 3: Tabulated with Space Optimized w/o additional temp array. TC: O(N * maxWeight), SC: O(maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> cache(maxWeight + 1, 0);
	
	for(int idx = n - 1; idx >= 0; idx--) {
		for(int currWeight = maxWeight; currWeight >= weight[idx]; currWeight--) {
			int include = value[idx] + cache[currWeight - weight[idx]];
			int exclude = cache[currWeight];
			cache[currWeight] = max(include, exclude);
		}
	}

	return cache[maxWeight];
}
