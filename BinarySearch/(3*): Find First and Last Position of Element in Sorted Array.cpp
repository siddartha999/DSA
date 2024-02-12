/**
* Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
**/

//Approach 1: TC: O(logN), SC: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findIndex(nums, target, true);
        if(left == -1) {
            return {-1, -1};
        }
        int right = findIndex(nums, target, false);
        return {left, right};
    }
private:
    int findIndex(vector<int>& nums, int& target, bool isLeft) {
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                res = mid;
                if(isLeft) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};







// Approach 2: Mildly optimized. TC: O(logN), SC: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findIndex(nums, target, 0, nums.size() -1, true);
        if(left == -1) {
            return {-1, -1};
        }
        int right = findIndex(nums, target, left, nums.size() - 1, false);
        return {left, right};
    }
private:
    int findIndex(vector<int>& nums, int& target, int left, int right, bool isLeft) {
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                res = mid;
                if(isLeft) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
