/**
* Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
* Reference: https://www.youtube.com/watch?v=auS1fynpnjo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=57
**/

//Approach 1: TC: O(N * M * N), SC: O(N * M)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        vector<vector<int>> cache(matrix.size(), vector<int> (matrix[0].size(), 0));
        
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(matrix[row][col] == 0) cache[row][col] = 0;
                else {
                    //Single-side square
                    cache[row][col] = (row > 0) ? (cache[row - 1][col] + 1) : 1;
                    count += 1;

                    //Multi-side square possibility
                    int val = cache[row][col];
                    for(int target = 2; target <= val; target++) {
                        if(col - target + 1 < 0) continue;
                        int idx = col - 1;
                        while(idx >= (col - target + 1) && cache[row][idx] >= target) idx--;
                        if(idx < (col - target + 1)) count += 1;
                    }
                }
            }
        }

        return count;
    }
};




// Approach 2: TC: O(N * M), SC: O(N * M)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        vector<vector<int>> cache(matrix.size(), vector<int> (matrix[0].size(), 0));
        
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[row].size(); col++) {
                if(matrix[row][col] == 0) cache[row][col] = 0;
                else {
                    if( (row - 1 >= 0) && (col - 1 >= 0)) {
                        cache[row][col] = 1 + min({cache[row - 1][col], cache[row][col - 1], cache[row - 1][col - 1]});
                    }
                    else {
                        cache[row][col] = 1;
                    }
                    count += cache[row][col];
                }
            }
        }

        return count;
    }
};
