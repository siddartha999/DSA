/**
  * Problem: You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, c  causing the left and the right side of the deleted substring to concatenate together.
  * Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
*/

class StackPair {
private:
    char c;
    int count;
public:
    StackPair(char _c, int _count) {
        c = _c;
        count = _count;
    }
    void incrementCount() {
        this->count++;
    }
    char getChar() {
        return this->c;
    }
    int getCount() {
        return this->count;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() < k) return s;
        stack<StackPair*> stack;
        for(char c: s) {
            if(stack.empty() || stack.top()->getChar() != c) {
                stack.push(new StackPair(c, 1));
            }
            else {
                if(stack.top()->getCount() + 1 == k) stack.pop();
                else stack.top()->incrementCount();
            }
        }
        string res = "";
        while(!stack.empty()) {
            char c = stack.top()->getChar();
            int freq = stack.top()->getCount();
            stack.pop();
            while(freq--) res += c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// TC: O(N), SC: O(N)
