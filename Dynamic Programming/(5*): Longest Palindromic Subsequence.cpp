/**
* Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/
* Reference: https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=29
**/


// Approach 1: Tabulated. TC: O(N * N), SC: O(N * N).
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> cache(s.size() + 1, vector<int> (s.size() + 1, 0));

        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= s.size(); j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    cache[i][j] = 1 + cache[i - 1][j - 1];
                }
                else {
                    cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
                }
            }
        }

        return cache[s.size()][s.size()];
    }
};





// Approach 2: Tabulated with Space Optimized. TC: O(N * N), SC: O(N).
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<int> cache(s.size() + 1, 0);

        for(int i = 1; i <= s.size(); i++) {
            vector<int> temp = cache;
            for(int j = 1; j <= s.size(); j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    temp[j] = 1 + cache[j - 1];
                }
                else {
                    temp[j] = max(cache[j], temp[j - 1]);
                }
            }
            cache = temp;
        }

        return cache[s.size()];
    }
};
