/**
* Problem Link: https://leetcode.com/problems/combinations/description/
* TC: 
**/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(1, n, k, res, {});
        return res;
    }

    void helper(int idx, int& n, int& k, vector<vector<int>>& res, vector<int> row) {
        if(row.size() == k) {
            res.push_back(row);
            return;
        }
        
        for(int i = idx; i <= n && (n - i + 1 + row.size() >= k); i++) {
            row.push_back(i);
            helper(i + 1, n, k, res, row);
            row.pop_back();
        }
    }
};
