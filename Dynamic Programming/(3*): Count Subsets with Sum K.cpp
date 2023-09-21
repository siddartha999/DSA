/**
* Problem Link: https://www.codingninjas.com/studio/problems/number-of-subsets_3952532
**/

// Approach 1: Brute Force. TC: O(2^N), SC: O(N).
int findWays(vector<int>& arr, int k)
{
	int count = 0;
	helper(arr, 0, k, count);
	return count;
}

void helper(vector<int>& nums, int idx, int target, int& count) {
	if(target == 0) {
		count = (count + 1) % (1000000007);
		return;
	}
	if(target < 0 || idx >= nums.size()) {
		return;
	}

	helper(nums, idx + 1, target - nums[idx], count);
	helper(nums, idx + 1, target, count);
}





// Approach 2: Memoized. TC: O(N * K), SC: O(N * K)
int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> cache(arr.size(), vector<int> (k + 1, -1));
	return helper(arr, 0, k, cache);
}

int helper(vector<int>& nums, int idx, int target, vector<vector<int>>& cache) {
	if(target == 0) {
		return 1;
	}
	if(target < 0 || idx >= nums.size()) {
		return 0;
	}

	if(cache[idx][target] != -1) return cache[idx][target];

	int count = 0;
	count += helper(nums, idx + 1, target - nums[idx], cache);
	count += helper(nums, idx + 1, target, cache);
	
	cache[idx][target] = count % 1000000007;
	return cache[idx][target];
}








// Approach 3: Tabulated. TC: O(N * K), SC: O(N * K)
int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> cache(arr.size() + 1, vector<int> (k + 1, 0));
	cache[arr.size()][0] = 1;

	for(int idx = arr.size() - 1; idx >= 0; idx--) {
		vector<vector<int>> temp = cache;
		temp[idx][0] = 1;
		for(int target = 1; target <= k; target++) {
			temp[idx][target] = (cache[idx + 1][target] + (arr[idx] > target ? 0 : cache[idx + 1][target - arr[idx]]) ) % 1000000007;
		}
		cache = temp;
	}

	return cache[0][k];
}








// Approach 4: Tabulated and Space Optimized. TC: O(N * K), SC: O(K)
int findWays(vector<int>& arr, int k)
{
	vector<int> cache(k + 1, 0);
	cache[0] = 1;

	for(int idx = arr.size() - 1; idx >= 0; idx--) {
		vector<int> temp = cache;
		temp[0] = 1;
		for(int target = 1; target <= k; target++) {
			temp[target] = (cache[target] + (arr[idx] > target ? 0 : cache[target - arr[idx]]) ) % 1000000007;
		}
		cache = temp;
	}

	return cache[k];
}
