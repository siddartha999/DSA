/**
* Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
**/

// TC: O(NlogN), SC: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] > arr[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
