/**
  * Problem: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
  
  * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        if(heights.size() == 1) return heights[0];
        int maxArea = 0;
        stack<pair<int, int>> stack;
        for(int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            if(stack.empty() || stack.top().first <= height) {
                stack.push({height, i});
            }
            else {
                int idx = i;
                while(!stack.empty() && stack.top().first > height) {
                    maxArea = max(maxArea, calculateArea(stack, idx, i));
                }
                stack.push({height, idx});
            }
        }

        while(!stack.empty()) {
           int idx = stack.top().second; 
           int i = heights.size();
           maxArea = max(maxArea, calculateArea(stack, idx, i));
        }
        return maxArea;
    }

private:
    int calculateArea(stack<pair<int, int>>& stack, int& idx, int& i) {
        int val = stack.top().first;
        idx = stack.top().second;
        stack.pop();
        int area = (val) * (i - idx);
        return area;
    }
};


//TC: O(N), SC: O(N)
