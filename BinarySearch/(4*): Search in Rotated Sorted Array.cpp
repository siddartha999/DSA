/**
* Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
* Reference: https://www.youtube.com/watch?v=5qGrJbHhqFs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=9
**/


// Approach 1. TC: O(logN), SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] <= nums[nums.size() - 1]) {
            return binarySearch(nums, 0, nums.size() - 1, target);
        }
        int leastValueIndex = determineLeastValueIndex(nums);
        if(target <= nums[nums.size() - 1]) {
            return binarySearch(nums, leastValueIndex, nums.size() - 1, target);
        }
        return binarySearch(nums, 0, leastValueIndex - 1, target);
    }
private: 
    int determineLeastValueIndex(vector<int>& nums) {
        if(nums[0] <= nums[nums.size() - 1]) return 0;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int prevIndex = (mid - 1 >= left) ? mid - 1 : right;
            int nextIndex = (mid + 1 <= right) ? mid + 1 : left;
            if(nums[mid] < nums[prevIndex] && nums[mid] < nums[nextIndex]) return mid;
            if(nums[right] > nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }

private:
    int binarySearch(vector<int>& nums, int left, int right, int& target) {
        if(left > right) return -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};








// Approach 2. TC: O(logN), SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left = 0, right = nums.size() - 1;
       while(left <= right) {
           int mid = left + (right - left) / 2;
           if(nums[mid] == target) return mid;
           //Left subsection is sorted
           if(nums[left] <= nums[mid]) {
                if(target >= nums[left] && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
           } 
           else { //right subsection is sorted
               if(target >= nums[mid] && target <= nums[right]) left = mid + 1;
               else right = mid - 1;
           }
       }
       return -1;
    }
};
