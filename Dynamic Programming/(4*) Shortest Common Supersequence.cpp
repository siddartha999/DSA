/**
* Problem Link: https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493
**/

// TC: O(N * M), SC: O(N * M).
string shortestSupersequence(string a, string b)
{
	vector<vector<int>> cache(a.size() + 1, vector<int> (b.size() + 1, 0));
	for(int i = 1; i <= a.size(); i++) {
		for(int j = 1; j <= b.size(); j++) {
			if(a[i - 1] == b[j - 1]) {
				cache[i][j] = 1 + cache[i - 1][j - 1];
			} 
			else {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}

	string res = "";
	int i = a.size() - 1, j = b.size() - 1;

	while(i >= 0 && j >= 0) {
		if(a[i] == b[j]) {
			res += a[i];
			i--;
			j--;
		}
		else {
			if(cache[i + 1][j + 1] == cache[i][j + 1]) {
				res += a[i];
				i--;
			}
			else {
				res += b[j];
				j--;
			}
		}

	}

	while(i >= 0) res += a[i--];
	while(j >= 0) res += b[j--];

	reverse(res.begin(), res.end());
	return res;
}
