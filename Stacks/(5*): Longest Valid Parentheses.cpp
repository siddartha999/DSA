/**
* Link: https://leetcode.com/problems/longest-valid-parentheses/description/
*/

//Approach 1: TC: O(N), SC: O(N)

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        stack<int> stack;
        stack.push(-1);
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(') stack.push(i);
            else {
                stack.pop();
                if(stack.empty()) stack.push(i);
                else longest = max(longest, i - stack.top());
            }
        }
        return longest;
    }
};





// Approach 2: TC: O(N), SC: O(1)
 class Solution {
public:
    int longestValidParentheses(string s) {
        int leftCount = 0, rightCount = 0;
        int longest = 0;
        for(char c: s) {
            if(c == '(') leftCount++;
            else rightCount++;
            
            if(leftCount == rightCount) longest = max(longest, leftCount * 2);
            else if(leftCount < rightCount) {
                leftCount = 0; rightCount = 0;
            }
        }

        leftCount = 0; rightCount = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if(c == '(') leftCount++;
            else rightCount++;

            if(leftCount == rightCount) longest = max(longest, leftCount * 2);
            else if(leftCount > rightCount) {
                leftCount = 0; rightCount = 0;
            }
        }

        // else: longest = max(longest, min(leftCount, rightCount)); is NOT valid
        // as ()(() would lead to '4' i.e, this statement would miss the demarcation
        // between the valid parantheses
        return longest;
    }
};

