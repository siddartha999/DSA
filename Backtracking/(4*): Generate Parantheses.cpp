/**
* Problem Link: https://leetcode.com/problems/generate-parentheses/description/
**/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, 0, res, "");
        return res;
    }
private:
    void helper(int& n, int open, int close, vector<string>& res, string row) {
        if(row.size() == n * 2) {
            res.push_back(row);
            return;
        }
        if(open < n) helper(n, open + 1, close, res, row + '(');
        if(open > close) helper(n, open, close + 1, res, row + ')');
    }
};
