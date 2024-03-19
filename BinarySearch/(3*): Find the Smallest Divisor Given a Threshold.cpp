/**
* Problem Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
**/

// TC: O(N * log(maxValue)), SC: O(1)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxVal = nums[0];
        for(int num: nums) maxVal = max(maxVal, num);
        int left = 1, right = maxVal;
        int res = maxVal;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int num: nums) {
                count += (num / mid) + (num % mid == 0 ? 0 : 1);
            }
            if(count <= threshold) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};
