/**
* Link: https://leetcode.com/problems/asteroid-collision/description/
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for(int asteroid: asteroids) {
            bool isAdd = true;
            while(!stack.empty() && stack.top() > 0 && asteroid < 0) {
                if(abs(asteroid) > stack.top()) stack.pop();
                else { //Loop should end as the current asteroid is done for
                    isAdd = false;
                    if(abs(asteroid) == stack.top()) stack.pop();
                    break;
                }
            }
            if(isAdd == true) {
                stack.push(asteroid);
            }
        }
        vector<int> res;
        while(!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// TC: O(N), SC:O(N)
