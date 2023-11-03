/**
* Problem Link: https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
* TC: O(N * M * (N + M))?, SC: O(N * M)
* A fun problem to solve!
**/

class Solution
{
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    vector<string> res;
		    vector<vector<int>> cache(s.size() + 1, vector<int> (t.size() + 1, 0));
		    unordered_map<int, unordered_map<int, unordered_set<string>>> dp;
		    int lcs = 0;
		    
		    for(int i = 0; i <= s.size(); i++) {
		        dp[i][t.size()].insert("");
		    }
		    for(int j = 0; j <= t.size(); j++) {
		        dp[s.size()][j].insert("");
		    }
		    
		    for(int i = s.size() - 1; i >= 0; i--) {
		        for(int j = t.size() - 1; j >= 0; j--) {
		            unordered_set<string> tt;
		            if(s[i] == t[j]) {
		                cache[i][j] = 1 + cache[i + 1][j + 1];
		                for(string ss: dp[i + 1][j + 1]) {
		                    string gg = s[i] + ss;
		                    tt.insert(gg);
		                }
		            }
		            else {
		                cache[i][j] = max(cache[i + 1][j], cache[i][j + 1]);
		                if(cache[i + 1][j] == cache[i][j + 1]) {
		                    for(string ss: dp[i + 1][j]) {
		                        tt.insert(ss);
		                    }
		                    for(string ss: dp[i][j + 1]) {
		                        tt.insert(ss);
		                    }
		                }
		                else if(cache[i + 1][j] > cache[i][j + 1]) {
		                    for(string ss: dp[i + 1][j]) {
		                        tt.insert(ss);
		                    }
		                }
		                else {
		                    for(string ss: dp[i][j + 1]) {
		                        tt.insert(ss);
		                    }
		                }
		            }
		            dp[i][j] = tt;
		            lcs = max(lcs, cache[i][j]);
		        }
		    }
		    
		    unordered_set<string> temp;
		    for(int i = 0; i < s.size(); i++) {
		        for(int j = 0; j < t.size(); j++) {
		            if(cache[i][j] == lcs) {
		                for(string ss: dp[i][j]) {
		                    temp.insert(ss);
		                }
		            }
		        }
		    }
		    
		    for(string str: temp) {
                 res.push_back(str);
            }
		    
		    sort(res.begin(), res.end());
		    return res;
		}
};
