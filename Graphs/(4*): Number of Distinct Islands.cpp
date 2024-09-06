/**
/* https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
**/

// TC: O(N * M), SC: O(N * M)
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> patterns;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] == 1) {
                    string pattern = helper(grid, row, col, "c", 0);
                    patterns.insert(pattern);
                }
            }
        }
        return patterns.size();
    }
private:
    string helper(vector<vector<int>>& grid, int row, int col, string route, int level) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] != 1) {
            return "";
        }
        
        grid[row][col] = 0;
        string str = route + ":" + to_string(level) + ":";
        str += helper(grid, row - 1, col, "t", level + 1);
        str += helper(grid, row, col - 1, "l", level + 1);
        str += helper(grid, row + 1, col, "d", level + 1);
        str += helper(grid, row, col + 1, "r", level + 1);
        return str;
    }
};
