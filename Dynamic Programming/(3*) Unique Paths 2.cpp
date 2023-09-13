/**
* Problem Link: https://www.codingninjas.com/studio/problems/maze-obstacles_977241
**/



// Approach 1: TC: O(n * M), SC: O(N + M + 2)
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if(mat[n - 1][m - 1] == -1 || mat[0][0] == -1) return 0;
    vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));
    cache[n][m - 1] = 1;
    int mod = 1000000007;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(mat[i][j] != -1) cache[i][j] = (cache[i + 1][j] + cache[i][j + 1]) % mod;
        }
    }
    return cache[0][0];
}






// Approach 2: TC: O(N * M), SC: O(M + 1)
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if(mat[n - 1][m - 1] == -1 || mat[0][0] == -1) return 0;
    vector<int> cache(m + 1, 0);
    int mod = 1000000007;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(i == n - 1 && j == m- 1) {
                cache[j] = 1;
            }
            else {
                if(mat[i][j] != -1) cache[j] = (cache[j] + cache[j + 1]) % mod;
                else cache[j] = 0;
            }
        }
    }
    return cache[0];
}
