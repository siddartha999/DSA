/**
* Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
**/

// TC: O(N^2), SC: O(N)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }
                    else if(lis[i] == lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLis = 1, maxCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(lis[i] > maxLis) {
                maxLis = lis[i];
                maxCount = count[i];
            }
            else if(lis[i] == maxLis) {
                maxCount += count[i];
            }
        }

        return maxCount;
    }
};
