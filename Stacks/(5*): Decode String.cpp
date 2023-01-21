/**
* Link: https://leetcode.com/problems/decode-string/description/
*/

//Approach 1: Does it's job in the interview but not pretty enough. TC: O(N), SC: O(N)

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<char> stack;
        for(char c: s) {
            if(c == ']') {
                string temp = "";
                while(!stack.empty() && stack.top() != '[') {
                    temp += stack.top();
                    stack.pop();
                }
                reverse(temp.begin(), temp.end());
                string num = "";
                stack.pop(); //remove the '['
                while(!stack.empty() && isdigit(stack.top())) {
                    num += stack.top();
                    stack.pop(); 
                }
                reverse(num.begin(), num.end());
                int nn = stoi(num);
                while(nn--) {
                    for(char cc: temp) stack.push(cc);
                }
            }
            else {
                stack.push(c);
            }
        }

        while(!stack.empty()) {
            res += stack.top();
            stack.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


//Approach 2: A much more elegant solution. TC:O(N), SC: O(N)

class Solution {
public:
    string decodeString(string s) {
        string currentString = "";
        int currentNum = 0;
        stack<string> stack;
        for(char c: s) {
            if(c == '[') {
                stack.push(currentString);
                stack.push(to_string(currentNum));
                currentNum = 0;
                currentString = "";
            }
            else if(c == ']') {
                int num = stoi(stack.top());
                stack.pop();
                string prevString = stack.top();
                stack.pop();
                string temp = prevString;
                while(num--) temp += currentString;
                currentString = temp;
            }
            else if(isdigit(c)) {
                currentNum = currentNum * 10 + (int)(c - '0');
            }
            else {
                currentString += c;
            }
        }

        return currentString;
    }
};
