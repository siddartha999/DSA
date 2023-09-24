/**
* Problem Link: https://www.codingninjas.com/studio/problems/minimum-insertions-to-make-palindrome_985293
* Reference: https://www.youtube.com/watch?v=xPBLEj41rFU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30
**/

// TC: O(N * N), SC: O(N)
int minimumInsertions(string &str)
{
	string str1 = str;
	string str2 = str;
	reverse(str2.begin(), str2.end());

	vector<int> cache(str.size() + 1, 0);

	for(int i = 1; i <= str.size(); i++) {
		vector<int> temp = cache;
		for(int j = 1; j <= str.size(); j++) {
			if(str1[i - 1] == str2[j - 1]) {
				temp[j] = 1 + cache[j - 1];
			}
			else {
				temp[j] = max(temp[j - 1], cache[j]);
			}
		}
		cache = temp;
	}

	return str.size() - cache[str.size()];
}
