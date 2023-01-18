/**
  * Problem: You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, c  causing the left and the right side of the deleted substring to concatenate together.
  * Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() < k) return s;
        stack<pair<char, int>> stack;
        for(char c: s) {
            if(stack.empty() || stack.top().first != c) {
                stack.push({c, 1});
            }
            else {
                if(stack.top().second + 1 == k) stack.pop();
                else stack.top().second++;
            }
        }
        string res = "";
        while(!stack.empty()) {
            char c = stack.top().first;
            int freq = stack.top().second;
            stack.pop();
            while(freq--) res += c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// TC: O(N), SC: O(N)
