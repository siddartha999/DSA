/**
* Problem link: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
**/


// TC: O(M * N), SC: O(M * N). A standard Level Order traversal.
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(grid[destination.first][destination.second] != 1) return -1;
        queue<pair<int, int>> bfs;
        bfs.push(source);
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int levels = 0;
        while(bfs.size() > 0) {
            int size = bfs.size();
            while(size--) {
                pair<int, int> cell = bfs.front();
                int x = cell.first;
                int y = cell.second;
                bfs.pop();
                if(x == destination.first && y == destination.second) {
                    return levels;
                }
                if(x + 1 < grid.size() && grid[x + 1][y] == 1 && 
                    visited[x + 1][y] == false) {
                    bfs.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                if(x - 1 >= 0 && grid[x - 1][y] == 1 && 
                    visited[x - 1][y] == false) {
                    bfs.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                if(y + 1 < grid[0].size() && grid[x][y + 1] == 1 && 
                    visited[x][y + 1] == false) {
                    bfs.push({x, y + 1});
                    visited[x][y + 1] = true;
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 1 && 
                    visited[x][y - 1] == false) {
                    bfs.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
            }
            levels++;
        }
        return -1;
    }
};
