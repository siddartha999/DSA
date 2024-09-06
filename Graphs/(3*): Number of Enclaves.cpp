/**
* Problem link: https://leetcode.com/problems/number-of-enclaves/description/
**/

// TC: O(N * M), SC: O(1)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(row == 0 || col == 0 || row == grid.size() - 1 || col == grid[row].size() - 1) {
                    helper(grid, row, col);
                }
            }
        }

        int count = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] == 1) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    void helper(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] != 1) {
            return;
        }

        grid[row][col] = 2;
        helper(grid, row - 1, col);
        helper(grid, row, col - 1);
        helper(grid, row + 1, col);
        helper(grid, row, col + 1);
    }
};
