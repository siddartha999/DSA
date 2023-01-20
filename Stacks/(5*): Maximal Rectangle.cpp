/**
* Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
* Link: https://leetcode.com/problems/maximal-rectangle/description/
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int maxArea = 0;

        //construct the heights array representing heights of rectangles in the matrix
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(matrix[row][col] == '0') {
                    heights[col] = 0;
                }
                else {
                    heights[col] += 1;
                }
            }
            int area = calculateArea(heights);
            maxArea = max(maxArea, area);
        }
        //return the max rectangle area
        return maxArea;
    }

private:
    int calculateArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack;
        for(int idx = 0; idx < heights.size(); idx++) {
            int height = heights[idx];
            if(stack.empty() || stack.top().first <= height) {
                stack.push({height, idx});
            }
            else {
                int curIdx = idx;
                while(!stack.empty() && stack.top().first > height) {
                    int topHeight = stack.top().first;
                    curIdx = stack.top().second;
                    stack.pop();
                    int area = (topHeight) * (idx - curIdx);
                    maxArea = max(maxArea, area);
                }
                stack.push({height, curIdx});
            }
        }

        while(!stack.empty()) {
            int topHeight = stack.top().first;
            int curIdx = stack.top().second;
            stack.pop();
            int area = (topHeight) * (heights.size() - curIdx);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

//TC: O(Row * Col * Col), SC: O(Col)
