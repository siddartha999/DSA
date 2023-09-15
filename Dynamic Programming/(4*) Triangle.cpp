/**
* Problem Link: https://leetcode.com/problems/triangle/description/
**/

// Approach 1: TC: O(N * N), SC: O(N)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> cache(rows, INT_MAX);
        cache[0] = triangle[0][0];
        for(int i = 1; i < rows; i++) {
            vector<int> temp = cache;
            for(int j = 0; j < triangle[i].size(); j++) {
                temp[j] = triangle[i][j] + min(j - 1 < 0 ? INT_MAX : cache[j - 1], cache[j]);
            }
            cache = temp;
        }

        int res = INT_MAX;
        for(int val: cache) res = min(res, val);
        return res;
    }
};



// Approach 2: TC: O(N * N), SC: O(N)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(rows == 1) return triangle[0][0];
        vector<int> cache(rows);

        for(int col = 0; col < rows; col++) {
            cache[col] = triangle[rows - 1][col];
        }

        for(int row = rows - 2; row >= 0; row--) {
            for(int col = 0; col <= row; col++) {
                cache[col] = triangle[row][col] + min(cache[col], cache[col + 1]);
            }
        }

        return cache[0];
    }
};
