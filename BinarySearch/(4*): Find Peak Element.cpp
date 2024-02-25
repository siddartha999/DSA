/**
* Problem Link: https://leetcode.com/problems/find-peak-element/description/
* Reference: https://www.youtube.com/watch?v=cXxmbemS6XM&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=10
* The problem statement fails to clarify that consecutive elements aren't duplicated.
**/

//Approach 1: Brute Force. TC: O(N), SC: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
        }

        return -1;
    }
};




//Approach 2: Binary Search. TC: O(logN), SC:O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        int left = 1, right = nums.size() - 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            if(nums[mid] < nums[mid - 1]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

        }

        return -1;
    }
};
