/**
* Problem Link: https://leetcode.com/problems/kth-missing-positive-number/description/
* Reference: https://www.youtube.com/watch?v=uZ0N_hZpyps&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=18
**/

//Approach 1: TC: O(N), SC: O(1).
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        for(int num: nums) {
            if(num <= k) k++;
            else break;
        }
        return k;
    }
};



//Approach 2: TC: O(logN), SC: O(1).
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int missingNumbers = (nums[mid] - mid - 1);
            if(missingNumbers >= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        int num = right == -1 ? 1 : nums[right];
        return num + k - (num - right - 1);
    }
};
