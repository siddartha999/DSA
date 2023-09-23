/**
* Problem Link: https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383
* TC: O(N * M), SC: O(N * M).
**/

string findLCS(int n, int m,string &s1, string &s2){
	string res = "";
	vector<vector<int>> cache(n + 1, vector<int> (m + 1, 0));

	for(int i = n - 1; i >= 0; i--) {
		for(int j = m - 1; j >= 0; j--) {
			if(s1[i] == s2[j]) {
				cache[i][j] = 1 + cache[i + 1][j + 1];
			}
			else {
				cache[i][j] = max(cache[i + 1][j], cache[i][j + 1]);
			}
		}
	}

	int i = 0, j = 0;
	while(i < n && j < m) {
		if(s1[i] == s2[j]) {
			res += s1[i];
			i++;
			j++;
		}
		else {
			if(i + 1 < n && cache[i][j] == cache[i + 1][j]) i++;
			else j++;
		}
	}

	return res;	
}
