/**
* Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
**/

// TC: O(N * log(maxValue)), SC: O(1)
class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        long long requiredFlowers = (long long)m * k;
        if(requiredFlowers > nums.size()) return -1;

        int left = INT_MAX, right = INT_MIN;
        for(int num: nums) {
            left = min(left, num);
            right = max(right, num);
        }
        int res = INT_MAX;
        while(left <= right) {
            int day = left + (right - left) / 2;
            int bouquetCount = 0;
            int currentCount = 0;
            for(int num: nums) {
                if(num <= day) {
                    currentCount++;
                    if(currentCount == k) {
                        bouquetCount++;
                        currentCount = 0;
                    }
                    if(bouquetCount == m) {
                        res = day;
                        break;
                    }
                }
                else {
                    currentCount = 0;
                }
            }

            if(bouquetCount == m) { //Success
                right = day - 1;
            }
            else { //Failure
                left = day + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
