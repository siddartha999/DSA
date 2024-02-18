/**
* Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
* Reference: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=7
**/

// TC: O(logN), SC: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int minVal = INT_MAX;
        while(left <= right) {
            int mid = (left) + (right - left) / 2;
            if(nums[mid] >= nums[left] && nums[mid] <= nums[right]) { //entire sub-section is sorted
                minVal = min(minVal, nums[left]);
                break;
            }
            else if(nums[mid] >= nums[left]) { //left subsection is sorted
                minVal = min(minVal, nums[left]);
                left = mid + 1;
            }
            else { //right subsection is sorted
                minVal = min(minVal, nums[mid]);
                right = mid - 1;
            }
        }
        return minVal;
    }
};
