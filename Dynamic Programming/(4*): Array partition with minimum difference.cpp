/**
* Problem Link: https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
* Reference: https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=17
**/

//Approach 1: Brute Force. TC: O(2^N), SC: O(N)
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
	for(int num: arr) totalSum += num;
	int target = totalSum / 2;
	int minDifference = INT_MAX;
	helper(arr, 0, target, minDifference);
	int firstSubsetSum = target - minDifference;
	int secondSubsetSum = totalSum - firstSubsetSum;
	return abs(firstSubsetSum - secondSubsetSum);
}

void helper(vector<int>& nums, int idx, int target, int& minDifference) {
	if(idx >= nums.size()) {
		if(abs(target) < abs(minDifference)) minDifference = target;
		return;
	}
	helper(nums, idx + 1, target - nums[idx], minDifference);
	helper(nums, idx + 1, target, minDifference);
}








//Approach 2: Memoized. TC: O(N * (TotalSum / 2) * 2), SC: O(N * (TotalSum / 2) * 2)
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
	for(int num: arr) totalSum += num;
	int target = totalSum / 2;
	vector<vector<vector<int>>> cache(arr.size(), vector<vector<int>> (target + 1, vector<int> (2, INT_MAX)));
	
	int firstSubsetSum = target - helper(arr, 0, target, cache);
	int secondSubsetSum = totalSum - firstSubsetSum;
	return abs(firstSubsetSum - secondSubsetSum);
}

int helper(vector<int>& nums, int idx, int target, vector<vector<vector<int>>>& cache) {
	int include = target - nums[idx];
	int notInclude = target;
	int targetSign = target < 0 ? 0 : 1;

	if(idx == nums.size() - 1) {
		if(abs(include) <= abs(notInclude))  return include;
		else return notInclude;
	}

	if(cache[idx][abs(target)][targetSign] != INT_MAX) return cache[idx][abs(target)][targetSign];

	int includeRes = helper(nums, idx + 1, include, cache);
	int notIncludeRes = helper(nums, idx + 1, notInclude, cache);

	if(abs(includeRes) <= abs(notIncludeRes)) cache[idx][abs(target)][targetSign] = includeRes;
	else cache[idx][abs(target)][targetSign] = notIncludeRes;
	return cache[idx][abs(target)][targetSign];
}




//Approach 3: Tabulation Space Optimized. TC: O(N * (TotalSum / 2)), SC: O((TotalSum / 2))
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
	for(int num: arr) totalSum += num;
	int target = (totalSum / 2);
	
	vector<bool> cache(target + 1, false);
	cache[0] = true;

	for(int idx = n - 1; idx >= 0; idx--) {
		vector<bool> temp = cache;
		temp[0] = true;
		for(int currentTarget = 1; currentTarget <= target; currentTarget++) {
			bool include = (currentTarget - arr[idx] >= 0) ? cache[currentTarget - arr[idx]] : false;
			bool notInclude = cache[currentTarget];

			if(include == true || notInclude == true) temp[currentTarget] = true;
			else temp[currentTarget] = false;
		}
		cache = temp;
	}

	int minDifference = INT_MAX;
	for(int firstSubsetSum = 0; firstSubsetSum <= target; firstSubsetSum++) {
		if(cache[firstSubsetSum] == true) {
			int secondSubsetSum = totalSum - firstSubsetSum;
			minDifference = min(minDifference, abs(firstSubsetSum - secondSubsetSum));
		}
	}

	return minDifference;
}

