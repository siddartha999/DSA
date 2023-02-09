/**
* Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // 1. Remove only if there is an imbalance leftCount != rightCount
        // 2. If at any point in the string, rightCount > leftCount

        stack<char> stack;
        int leftCount = 0;
        for(char c: s) {
            if(c == '(') {
                leftCount++;
                stack.push(c);
            }
            else if(c == ')') {
                leftCount--;
                if(leftCount >= 0) stack.push(c);
                else leftCount = 0; //Extra ')' check
            }
            else {
                stack.push(c);
            }
        }

        string res = "";
        while(!stack.empty()) {
            char c = stack.top();
            if(c == '(') {
                if(leftCount > 0) leftCount--; //Extra '(' check
                else res += c;
            }
            else {
                res += c;
            }
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// TC; O(N), SC: O(N). There is another approach to solve this in O(1) space as well, but I feel it is not worth it / expected for interviews
