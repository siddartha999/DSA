/**
* Problem Link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
**/


// TC: O(N * 3), SC: O(1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(3, 0);
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        vector<int> temp(3, 0);
        for (int j = 0; j < 3; j++) {
          int prevIdx = (j - 1 + 3) % 3;
          int nextIdx = (j + 1) % 3;
          temp[j] = points[i][j] + max(dp[prevIdx], dp[nextIdx] );  
          maxVal = max(maxVal, temp[j]);
        }
        dp = temp;
    }

    return maxVal;
}
