/**
* Problem link: https://leetcode.com/problems/path-with-minimum-effort/description/
**/

// TC: O(E logV) => O(M * N * 4 log (M * N)), SC: O(M * N)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> bfs;
        bfs.push({0, {0, 0}});
        int rows = heights.size(), cols = heights[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        while(bfs.size() > 0) {
            int diff = bfs.top().first;
            int row = bfs.top().second.first;
            int col = bfs.top().second.second;
            bfs.pop();
            if(row == rows - 1 && col == cols - 1) {
                return diff;
            }
            if(visited[row][col] == true) continue;
            visited[row][col] = true;
            for(pair<int, int> dir: dirs) {
                int rowX = row + dir.first;
                int colY = col + dir.second;
                if(rowX >= 0 && rowX < rows && colY >= 0 && colY < cols) {
                    int currentDiff = abs(heights[rowX][colY] - heights[row][col]);
                    int maxDiff = max(diff, currentDiff);
                    bfs.push({maxDiff, {rowX, colY}});
                }
            }
        }
        return 0;  
    }
};
