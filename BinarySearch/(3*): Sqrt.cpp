/**
* Problem Link: https://leetcode.com/problems/sqrtx/
**/

// TC: O(logN), SC: O(1)
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x <= 3) return 1;
        int left = 1, right = x / 2;
        int res = x;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int quot = x / mid;
            if(quot <= mid) {
                res = quot;
                if(quot == mid) break;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};
