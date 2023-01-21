/**
  * Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
  
  * Link: https://leetcode.com/problems/trapping-rain-water/description/
*/

//Approach 1: TC: O(N), SC: O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int total = 0;

        leftMax[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        for(int i = 1; i < height.size() - 1; i++) {
            int minOfMax = min(leftMax[i], rightMax[i]);
            total += minOfMax - height[i];
        }
        
        return total;
    }
};




//Approach 2: TC: O(N), SC: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int leftMax = height[0];
        int rightMax = height[height.size() - 1];
        int leftIdx = 0, rightIdx = height.size() - 1;
        while(leftIdx <= rightIdx) {
            if(leftMax < rightMax) {
                leftMax = max(leftMax, height[leftIdx]);
                total += leftMax - height[leftIdx];
                leftIdx++;
            }
            else {
                rightMax = max(rightMax, height[rightIdx]);
                total += rightMax - height[rightIdx];
                rightIdx--;
            }
        }
        return total;
    }
};
