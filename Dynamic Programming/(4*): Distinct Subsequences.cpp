/**
* Problem Link: https://leetcode.com/problems/distinct-subsequences/description/
**/

// Approach 1: Brute Force. TC: O(2^N * 2^M), SC: O(N + M)
int distinctSubsequences(string &str, string &sub)
{
	return helper(str, 0, sub, 0);
}

int helper(string& a, int i, string& b, int j) {
	if(j >= b.size()) return 1;
	if(i >= a.size()) return 0;
	int include = 0;
	if(a[i] == b[j]) include = helper(a, i + 1, b, j + 1);
	int exclude = helper(a, i + 1, b, j);
	return (include + exclude) % 1000000007;
}





// Approach 2: Memoized. TC: O(N * M), SC: O(N * M) + O(N + M)
int distinctSubsequences(string &str, string &sub)
{
	vector<vector<int>> cache(str.size(), vector<int> (sub.size(), -1));
	return helper(str, 0, sub, 0, cache);
}

int helper(string& a, int i, string& b, int j, vector<vector<int>>& cache) {
	if(j >= b.size()) return 1;
	if(i >= a.size()) return 0;

	if(cache[i][j] != -1) return cache[i][j];

	int include = 0;
	if(a[i] == b[j]) include = helper(a, i + 1, b, j + 1, cache);
	int exclude = helper(a, i + 1, b, j, cache);

	cache[i][j] = (include + exclude) % 1000000007;
	return cache[i][j];
}








// Approach 3: Tabulated. TC: O(N * M), SC: O(N * M)
int distinctSubsequences(string &str, string &sub)
{
	vector<vector<int>> cache(str.size() + 1, vector<int> (sub.size() + 1, 0));

	for(int idx = 0; idx <= str.size(); idx++) cache[idx][sub.size()] = 1;

	for(int i = str.size() - 1; i >= 0; i--) {
		for(int j = sub.size() - 1; j >= 0; j--) {
			int include = (str[i] == sub[j]) ? cache[i + 1][j + 1] : 0;
			int exclude = cache[i + 1][j];
			cache[i][j] = (include + exclude) % 1000000007;
		}
	}

	return cache[0][0];
}










// Approach 4: Tabulated with Space Optimized. TC: O(N * M), SC: O(M)
int distinctSubsequences(string &str, string &sub)
{
	vector<int> cache(sub.size() + 1, 0);
	cache[sub.size()] = 1;

	for(int i = str.size() - 1; i >= 0; i--) {
		vector<int> temp = cache;
		for(int j = sub.size() - 1; j >= 0; j--) {
			int include = (str[i] == sub[j]) ? cache[j + 1] : 0;
			int exclude = cache[j];
			temp[j] = (include + exclude) % 1000000007;
		}
		cache = temp;
	}

	return cache[0];
}









// Approach 5: Tabulated with Space Optimized and with a Single array. TC: O(N * M), SC: O(M)
int distinctSubsequences(string &str, string &sub)
{
	vector<int> cache(sub.size() + 1, 0);
	cache[sub.size()] = 1;

	for(int i = str.size() - 1; i >= 0; i--) {
		for(int j = 0; j < sub.size(); j++) {
			int include = (str[i] == sub[j]) ? cache[j + 1] : 0;
			int exclude = cache[j];
			cache[j] = (include + exclude) % 1000000007;
		}
	}

	return cache[0];
}
