/**
* Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
**/

//Approach 1: XOR. TC: O(N), SC: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int num: nums) {
            if(res == 0) res = num;
            else res = res ^ num;
        }
        return res;
    }
};




// Approach 2: Binary Search. TC: O(logN), SC: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int leftLen = mid - left;
            int rightLen = right - mid;
            if(mid == 0 || mid == nums.size() - 1) return nums[mid]; //Extreme scenario
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            if(nums[mid] == nums[mid - 1]) {
                if(leftLen % 2 == 0) right = mid - 2;
                else left = mid + 1;
            }
            else {
                if(rightLen % 2 == 0) left = mid + 2;
                else right = mid - 1;
            }
        }
        return nums[left];
    }
};
