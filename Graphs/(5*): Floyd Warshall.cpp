/**
* Problem link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
**/

// TC: O(V^3)
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        for(int via = 0; via < mat.size(); via++) {
            for(int row = 0; row < mat.size(); row++) {
                for(int col = 0; col < mat[row].size(); col++) {
                    if(row == via || col == via || mat[row][via] == -1 || mat[via][col] == -1) continue;
                    if(mat[row][col] == -1) {
                        mat[row][col] = mat[row][via] + mat[via][col];
                    }
                    else {
                        mat[row][col] = min(mat[row][col], mat[row][via] + mat[via][col]);   
                    }
                }
            }   
        }
    }
};
