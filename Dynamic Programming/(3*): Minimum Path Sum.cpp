/**
* Problem Link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
**/

// Approach 1: TC: O(N * M), SC: O(N + M + 2)
int minSumPath(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> cache (rows + 1, vector<int>(cols + 1, INT_MAX));
    cache[rows][cols - 1] = 0;
    for(int i = rows - 1; i >= 0; i--) {
        for(int j = cols - 1; j >= 0; j--) {
            cache[i][j] = grid[i][j] + min(cache[i + 1][j], cache[i][j + 1]);
        }
    }
    return cache[0][0];
}


// Approach 2: TC: O(N * M), SC: O(M)
int minSumPath(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> cache (cols, INT_MAX);
    cache[cols - 1] = 0;
    for(int i = rows - 1; i >= 0; i--) {
        for(int j = cols - 1; j >= 0; j--) {
            if(j == cols - 1) {
                cache[j] += grid[i][j];
            }
            else {
                cache[j] = grid[i][j] + min(cache[j], cache[j + 1]);
            }
        }
    }
    return cache[0];
}
