/**
* Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
**/

// TC: O(logN), worstCase: O(N). SC: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int minVal = INT_MAX;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == nums[left] && nums[mid] == nums[right]) { //Special case
                minVal = min(minVal, nums[mid]);
                left++;
                right--;
            }
            else if(nums[mid] >= nums[left] && nums[mid] <= nums[right]) { //entire sublist is sorted
                minVal = min(minVal, nums[left]);
                break;
            }
            else if(nums[mid] >= nums[left]) { //left sublist is sorted
                minVal = min(minVal, nums[left]);
                left = mid + 1;
            }
            else { //right sublist is sorted
                minVal = min(minVal, nums[mid]);
                right = mid - 1;
            }
        }

        return minVal;
    }
};
