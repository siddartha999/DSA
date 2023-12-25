/**
* Problem Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/
* Reference: https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54
**/

// Approach 1: Memoized. TC: O(N^3), SC: O(N) + O(N)
class Solution {
public:
    int minCut(string s) {
        vector<int> cache(s.size(), -1);
        return helper(s, 0, cache);
    }
private:
    int helper(string& s, int start, vector<int>& cache) {
        if(start >= s.size()) return -1;
        if(cache[start] != -1) return cache[start];
        int minCuts = s.size() - start;
        for(int idx = start; idx < s.size(); idx++)
        {
            if(isPalindrome(s, start, idx)) {
                int cut = 1 + helper(s, idx + 1, cache);
                minCuts = min(minCuts, cut);
            }
        }
        cache[start] = minCuts;
        return minCuts;
    }
private:
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
};





// Approach 2: Tabulated. TC: O(N^3), SC: O(N)
class Solution {
public:
    int minCut(string s) {
        vector<int> cache(s.size() + 1, 0);
        cache[s.size()] = -1;

        for(int i = s.size() - 1; i >= 0; i--) {
            int minCuts = s.size() - i;
            for(int idx = i; idx < s.size(); idx++) {
                if(isPalindrome(s, i, idx)) {
                    int cut = 1 + cache[idx + 1];
                    minCuts = min(minCuts, cut);
                }
            }
            cache[i] = minCuts;
        }

        return cache[0];
    }
    
private:
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
};






// Approach 3: Removed isPalindrome check. TC: O(N^2), SC: O(N^2)
class Solution {
public:
    int minCut(string s) {
        vector<int> cache(s.size() + 1, 0);
        vector<vector<bool>> pal(s.size(), vector<bool> (s.size(), false));
        cache[s.size()] = -1;

        for(int i = s.size() - 1; i >= 0; i--) {
            int minCuts = s.size() - i - 1;
            for(int idx = i; idx < s.size(); idx++) {
                if(s[i] == s[idx] && (idx - i < 3 || pal[i + 1][idx - 1])) {
                    pal[i][idx] = true;
                    minCuts = min(minCuts, 1 + cache[idx + 1]);
                }
            }
            cache[i] = minCuts;
        }

        return cache[0];
    }
};
