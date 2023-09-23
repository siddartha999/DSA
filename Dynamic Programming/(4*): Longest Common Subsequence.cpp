/**
* Problem Link: https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879
**/

// Approach 1: Brute Force. TC: O(2^N * 2^M), SC: O(N).
int lcs(string s, string t)
{
	return helper(s, s.size() - 1, t, t.size() - 1);
}

int helper(string& s, int sIndex, string& t, int tIndex) {
	if(sIndex < 0 || tIndex < 0) return 0;
	if(s[sIndex] == t[tIndex]) {
		return 1 + helper(s, sIndex - 1, t, tIndex - 1);
	}
	return max(helper(s, sIndex - 1, t, tIndex), helper(s, sIndex, t, tIndex - 1));
}





// Approach 2: Memoized. TC: O(N * M), SC: O(N * M) + O(max(N, M)).
int lcs(string s, string t)
{
	vector<vector<int>> cache(s.size(), vector<int> (t.size(), -1));
	return helper(s, s.size() - 1, t, t.size() - 1, cache);
}

int helper(string& s, int sIndex, string& t, int tIndex, vector<vector<int>>& cache) {
	if(sIndex < 0 || tIndex < 0) return 0;
	
	if(cache[sIndex][tIndex] != -1) return cache[sIndex][tIndex];

	if(s[sIndex] == t[tIndex]) {
		cache[sIndex][tIndex] = 1 + helper(s, sIndex - 1, t, tIndex - 1, cache);
		return cache[sIndex][tIndex];
	}

	cache[sIndex][tIndex] = max(helper(s, sIndex - 1, t, tIndex, cache), helper(s, sIndex, t, tIndex - 1, cache));
	return cache[sIndex][tIndex];
}








// Approach 3: Tabulated. TC: O(N * M), SC: O(N * M).
int lcs(string s, string t)
{
	vector<vector<int>> cache(s.size() + 1, vector<int> (t.size() + 1, 0));

	for(int sIndex = s.size() - 1; sIndex >= 0; sIndex--) {
		for(int tIndex = t.size() - 1; tIndex >= 0; tIndex--) {
			if(s[sIndex] == t[tIndex]) {
				cache[sIndex][tIndex] = 1 + cache[sIndex + 1][tIndex + 1];
			}
			else {
				cache[sIndex][tIndex] = max(cache[sIndex + 1][tIndex], cache[sIndex][tIndex + 1]);
			}
		}
	}

	return cache[0][0];
}







// Approach 4: Tabulated with Space Optimized. TC: O(N * M), SC: O(M).
int lcs(string s, string t)
{
	vector<int> cache(t.size() + 1, 0);

	for(int sIndex = s.size() - 1; sIndex >= 0; sIndex--) {
		vector<int> temp = cache;
		for(int tIndex = t.size() - 1; tIndex >= 0; tIndex--) {
			if(s[sIndex] == t[tIndex]) {
				temp[tIndex] = 1 + cache[tIndex + 1];
			}
			else {
				temp[tIndex] = max(temp[tIndex + 1], cache[tIndex]);
			}
		}
		cache = temp;
	}

	return cache[0];
}
