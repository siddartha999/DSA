/**
* Problem Link: https://leetcode.com/problems/largest-divisible-subset/
**/

// TC: O(N^2), SC: O(N * 3)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> lds(nums.size(), 1);
        vector<int> trace(nums.size(), -1);
        
        int maxVal = 1, maxIdx = 0; 

        for(int idx = 1; idx < nums.size(); idx++) {
            for(int prev = 0; prev < idx; prev++) {
                if( (nums[idx] % nums[prev] == 0)) {
                    if(lds[idx] < 1 + lds[prev]) {
                        lds[idx] = 1 + lds[prev];
                        trace[idx] = prev;
                    }
                }
            }
            if(lds[idx] > maxVal) {
                maxVal = lds[idx]; maxIdx = idx;
            }
        }

        vector<int> res(maxVal);
        int idx = maxVal - 1;
        while(maxIdx >= 0) {
            res[idx--] = nums[maxIdx];
            maxIdx = trace[maxIdx];
        }

        return res;
    }
};
