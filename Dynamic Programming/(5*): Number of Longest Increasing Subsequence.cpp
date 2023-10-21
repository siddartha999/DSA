/**
* Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
**/

// TC: O(N^2), SC: O(N)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        int maxLISLength = 1, maxCount = 1;

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(1 + lis[j] > lis[i]) {
                        lis[i] = 1 + lis[j];
                        count[i] = count[j];
                    }
                    else if(1 + lis[j] == lis[i]) {
                        count[i] += count[j];
                    }
                }
            }
            if(lis[i] > maxLISLength) {
                maxLISLength = lis[i];
                maxCount = count[i];
            }
            else if(lis[i] == maxLISLength) {
                maxCount += count[i];
            }
        }

        return maxCount;
    }
};
