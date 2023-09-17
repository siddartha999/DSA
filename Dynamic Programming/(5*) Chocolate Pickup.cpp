/**
* Problem Link: https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885
* Reference: https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14
**/

//Approach 1: Brute Force: TC: (3^N * 3^N), SC: O(N)

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return helper(grid, 0, 0, c - 1, r, c);
}

int helper(vector<vector<int>>& grid, int row, int col1, int col2, int& rows, int& cols) {
    if(col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) return INT_MIN;
    int val = 0;

    if(col1 == col2) {
         val =  grid[row][col1];
    }
    else {
        val = grid[row][col1] + grid[row][col2];
    }

    if(row == rows - 1) {
        return val;
    }

    int maxVal = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            maxVal = max(maxVal, helper(grid, row + 1, col1 + i, col2 + j, rows, cols));
        }
    }
    
    return val + maxVal;
}







// Approach 2: Memoized. TC: O(N * M * M * 9), SC: O(N * M * M)

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> cache(r, vector<vector<int>> (c, vector<int> (c, -1)));
    return helper(grid, 0, 0, c - 1, r, c, cache);
}

int helper(vector<vector<int>>& grid, int row, int col1, int col2, int& rows, int& cols, vector<vector<vector<int>>>& cache) {
    if(col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) return INT_MIN;

    if(cache[row][col1][col2] != -1) return cache[row][col1][col2];

    int val = 0;

    if(col1 == col2) {
         val =  grid[row][col1];
    }
    else {
        val = grid[row][col1] + grid[row][col2];
    }

    if(row == rows - 1) {
        return val;
    }

    int maxVal = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            maxVal = max(maxVal, helper(grid, row + 1, col1 + i, col2 + j, rows, cols, cache));
        }
    }
    cache[row][col1][col2] = val + maxVal;
    return val + maxVal;
}







// Approch 3: Tabulated. TC: O(N * M * M * 9), SC: O(N * M * M)

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> cache(r, vector<vector<int>> (c, vector<int> (c, INT_MIN)));
    
    for(int row = r - 1; row >= 0; row--) {
        for(int col1 = 0; col1 < c; col1++) {
            for(int col2 = 0; col2 < c; col2++) {
                int val = col1 == col2 ? grid[row][col1] : grid[row][col1] + grid[row][col2];
                if(row == r - 1) {
                    cache[row][col1][col2] = val;
                }
                else {
                    int maxVal = 0;
                    for(int i = -1; i <= 1; i++) {
                        for(int j = -1; j <= 1; j++) {
                            if(col1 + i < 0 || col1 + i >= c || col2 + j < 0 || col2 + j >= c) continue;
                            maxVal = max(maxVal, cache[row + 1][col1 + i][col2 + j]);
                        }
                    }
                    cache[row][col1][col2] = val + maxVal;
                }

            }
        }
    }

    return cache[0][0][c - 1];
}








// Appraoch 4: Tabulation Space Optimized. TC: O(N * M * M * 9), SC: O(M * M).

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> cache(c, vector<int> (c, INT_MIN));
    
    for(int row = r - 1; row >= 0; row--) {
        vector<vector<int>> temp = cache;
        for(int col1 = 0; col1 < c; col1++) {
            for(int col2 = 0; col2 < c; col2++) {
                int val = col1 == col2 ? grid[row][col1] : grid[row][col1] + grid[row][col2];
                if(row == r - 1) {
                    temp[col1][col2] = val;
                }
                else {
                    int maxVal = 0;
                    for(int i = -1; i <= 1; i++) {
                        for(int j = -1; j <= 1; j++) {
                            if(col1 + i < 0 || col1 + i >= c || col2 + j < 0 || col2 + j >= c) continue;
                            maxVal = max(maxVal, cache[col1 + i][col2 + j]);
                        }
                    }
                    temp[col1][col2] = val + maxVal;
                }

            }
        }
        cache = temp;
    }

    return cache[0][c - 1];
}
