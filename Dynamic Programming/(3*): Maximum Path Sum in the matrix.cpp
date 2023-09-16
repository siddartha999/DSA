/**
* Problem Link: https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998
**/

// Approach 1: TC: O(N * M), SC: O(N * M)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    vector<vector<int>> cache(rows, vector<int>(100, INT_MIN));
    for(int col = 0; col < matrix[rows - 1].size(); col++) {
        cache[rows - 1][col] = matrix[rows - 1][col];
    }

    for(int row = rows - 2; row >= 0; row--) {
        for(int col = 0; col < matrix[row].size(); col++) {
            cache[row][col] = matrix[row][col] + max(cache[row + 1][col], 
                                max(col - 1 >= 0 ? cache[row + 1][col - 1] : INT_MIN, col + 1 < matrix[row + 1].size() ? cache[row + 1][col + 1] : INT_MIN) );
        }
    }

    int res = INT_MIN;
    for(int col = 0; col < matrix[0].size(); col++) {
        res = max(res, cache[0][col]);
    }

    return res;
}








// Approach 2: TC: O(N * M), SC: O(M)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    vector<int> cache(100, INT_MIN);
    for(int col = 0; col < matrix[rows - 1].size(); col++) {
        cache[col] = matrix[rows - 1][col];
    }

    for(int row = rows - 2; row >= 0; row--) {
        vector<int> temp = cache;
        for(int col = 0; col < matrix[row].size(); col++) {
            temp[col] = matrix[row][col] + max(cache[col], 
                            max(col - 1 >= 0 ? cache[col - 1] : INT_MIN, col + 1 < matrix[row + 1].size() ? cache[col + 1] : INT_MIN) );
        }
        cache = temp;
    }

    int res = INT_MIN;
    for(int col = 0; col < matrix[0].size(); col++) {
        res = max(res, cache[col]);
    }

    return res;
}
