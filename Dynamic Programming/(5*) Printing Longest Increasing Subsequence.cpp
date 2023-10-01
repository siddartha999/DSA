/**
* Problem Link: https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
* Reference: https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
**/

// TC: O(N^2), SC: O(N)
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> lis (n, 1);
        vector<int> prevIdx(n, n);
        int maxVal = 0, maxIdx = 0;
        
        for(int idx = 1; idx < n; idx++) {
            for(int prev = 0; prev < idx; prev++) {
                if(arr[idx] > arr[prev]) {
                    if(1 + lis[prev] > lis[idx]) {
                        lis[idx] = 1 + lis[prev];
                        prevIdx[idx] = prev;
                    }
                }
                
            }
            if(lis[idx] > maxVal) {
                maxVal = lis[idx];
                maxIdx = idx;
            }
        }
        
        
        vector<int> res(maxVal);
        int idx = maxVal - 1;
        while(maxIdx < n) {
            res[idx--] = arr[maxIdx];
            maxIdx = prevIdx[maxIdx];
        }
    
        return res;
    }
};
