/**
* Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
* Reference: https://www.youtube.com/watch?v=w2G2W8l__pc&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=6
**/

// TC: O(logN), worstCase: O(N): SC: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;

            if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++; right--;
            }
            else if(nums[left] <= nums[mid]) { //Left sublist is sorted
                if(target >= nums[left] && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else { //right subList is sorted
                if(target >= nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};
