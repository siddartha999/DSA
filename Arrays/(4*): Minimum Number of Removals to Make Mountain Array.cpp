/**
* Problem Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
**/

// Approach 1: TC: O(N^2), SC: O(N). Not the most optimal solution, there are O(NlogN) solutions out there
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        vector<int> lds(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) lis[i] = max(lis[i], 1 + lis[j]);
            }
        }

        for(int i = nums.size() - 2; i >= 0; i--) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] > nums[j]) lds[i] = max(lds[i], 1 + lds[j]);
            }
        }

        //View the max.peak w.r.t the peaks(has both lis and lds) of the array
        int minRemovals = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(lis[i] == 1 || lds[i] == 1) continue;
            int mountainLength = lis[i] + lds[i] - 1;
            int removals = nums.size() - mountainLength;
            minRemovals = min(minRemovals, removals);
        }

        return minRemovals;
    }
};
