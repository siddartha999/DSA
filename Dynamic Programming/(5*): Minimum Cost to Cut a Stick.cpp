/**
* Problem Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
* Reference: https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51
**/

// Approach 1: Brute Force. Exponential Time Complexity
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        return helper(cuts, 1, cuts.size() - 2);
    }

    int helper(vector<int> cuts, int start, int end) {
        if(start > end) return 0;
        int minVal = INT_MAX;
        for(int i = start; i <= end; i++) {
            int cut = cuts[i];
            int val = (cuts[end + 1] - cuts[start - 1]) + helper(cuts, start, i - 1) + helper(cuts, i + 1, end);
            minVal = min(minVal, val);
        }
        return minVal;
    }
};




// Approach 2: Memoized. TC: O(N * N * N), SC: O(N * N * N)
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        return helper(cuts, 1, cuts.size() - 2);
    }

    int helper(vector<int> cuts, int start, int end) {
        if(start > end) return 0;
        int minVal = INT_MAX;
        for(int i = start; i <= end; i++) {
            int cut = cuts[i];
            int val = (cuts[end + 1] - cuts[start - 1]) + helper(cuts, start, i - 1) + helper(cuts, i + 1, end);
            minVal = min(minVal, val);
        }
        return minVal;
    }
};



// Approach 3: Tabulated. TC: O(N * N * N), SC: O(N * N)
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> cache(cuts.size(), vector<int> (cuts.size(), 0));

        for(int start = cuts.size() - 2; start >= 1; start--) {
            for(int end = start; end <= cuts.size() - 2; end++) {
                int minVal = INT_MAX;
                for(int i = start; i <= end; i++) {
                    int cut = cuts[i];
                    int val = (cuts[end + 1] - cuts[start - 1]) + cache[start][i - 1] + cache[i + 1][end];
                    minVal = min(minVal, val);
                }
                cache[start][end] = minVal;
            }            
        }

        return cache[1][cuts.size() - 2];
    }
};
