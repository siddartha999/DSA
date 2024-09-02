/**
* Problem Link: https://leetcode.com/problems/rotting-oranges/description/
**/

// TC: O(N * M), SC: O(N * M)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int oneCount = 0;
        queue<pair<int, int>> qq;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] == 1) {
                    oneCount++;
                }
                else if(grid[row][col] == 2) {
                    qq.push({row, col});
                }
            }
        }

        while(oneCount > 0 && !qq.empty()) {
            int size = qq.size();
            while(size--) {
                pair<int, int> location = qq.front();
                int row = location.first;
                int col = location.second;
                qq.pop();
                if(row - 1 >= 0 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    oneCount--;
                    qq.push({row - 1, col});
                }
                if(col - 1 >= 0 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    oneCount--;
                    qq.push({row, col-1});
                }
                if(row + 1 < grid.size() && grid[row+1][col] == 1) {
                    grid[row+1][col] = 2;
                    oneCount--;
                    qq.push({row + 1, col});
                }
                if(col + 1 < grid[row].size() && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    oneCount--;
                    qq.push({row, col + 1});
                }
            }
            time++;
        }

        return oneCount == 0 ? time : -1;
    }
};
