/**
* Problem Link: https://leetcode.com/problems/find-a-peak-element-ii/description/
* Reference: https://leetcode.com/problems/find-a-peak-element-ii/solutions/1338377/java-c-detailed-explanation/
**/

// TC: O(Rows * log(Columns)). SC: O(1)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        if(mat.size() == 1 && mat[0].size() == 1) return {{0, 0}};
        int rows = mat.size();
        int cols = mat[0].size();
        int left = 0, right = cols - 1;
        while(left <= right) {
            int maxInCol = INT_MIN;
            int maxRowInCol = -1;
            int mid = left + (right - left) / 2;
            for(int i = 0; i < rows; i++) {
                if(maxInCol < mat[i][mid]) {
                    maxInCol = mat[i][mid];
                    maxRowInCol = i;
                }
            }

            if((mid == 0 || mat[maxRowInCol][mid] > mat[maxRowInCol][mid - 1]) && (mid + 1 == cols || mat[maxRowInCol][mid] > mat[maxRowInCol][mid + 1])) {
                return {{maxRowInCol, mid}};
            }
            if(mid + 1 != cols && mat[maxRowInCol][mid] < mat[maxRowInCol][mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }            
        }

        return {{-1, -1}};
    }
};
