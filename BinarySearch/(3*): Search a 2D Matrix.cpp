/**
* Problem Link: https://leetcode.com/problems/search-a-2d-matrix/description/
**/


//TC: O(log(n * m)), SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0, high = (rows * cols) - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
