/**
  * Problem: Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order among all possible results.

* Link: https://leetcode.com/problems/remove-duplicate-letters/description/
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        for(char c: s) freq[c]++;
        unordered_set<char> visited;
        stack<char> stack;
        for(char c: s) {
            if(visited.find(c) != visited.end()) {
                freq[c]--;
                continue;
            }
            //Visiting the current character for the first time
            while(!stack.empty() && stack.top() > c && freq[stack.top()] > 0) {
                visited.erase(stack.top());
                stack.pop();
            }
            stack.push(c);
            visited.insert(c);
            freq[c]--;
        }
        string res = "";
        while(!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//TC: O(N), SC: O(N)
