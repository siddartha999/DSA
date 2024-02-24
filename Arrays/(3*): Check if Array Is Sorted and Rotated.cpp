/**
* Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
**/

//TC: O(N), SC: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int dropPoint = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) dropPoint++;
            if(dropPoint == 2) return false;
        }
        if(dropPoint == 0) return true;
        if(nums[0] >= nums[nums.size() - 1]) return true;
        return false;
    }
};
