/**
* Problem Link: https://leetcode.com/problems/longest-mountain-in-array/description/
**/

// Approach 1: Evolution of Largest Bitonic array solution. TC: O(N), SC: O(N)
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxLength = 0;
        vector<int> lis(arr.size(), 1);
        vector<int> lds(arr.size(), 1);

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > arr[i - 1]) lis[i] = 1 + lis[i - 1];
        }

        for(int i = arr.size() - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1]) lds[i] = 1 + lds[i + 1];  
        }

        for(int i = 0; i < arr.size(); i++) {
            if(lis[i] > 1 && lds[i] > 1) maxLength = max(maxLength, lis[i] + lds[i] - 1);
        }

        return maxLength;
    }
};



// Approach 2: Greedy-like. TC: O(N), SC: O(1)
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int res = 0;
        int i = 0;
        while(i < nums.size()) {
            int temp = i;
            //walk up
            while(i + 1 < nums.size() && nums[i] < nums[i + 1]) i++;
            if(i == temp) {
                i++;
                continue;
            }

            //Walk down
            int peak = i;
            while(i + 1 < nums.size() && nums[i] > nums[i + 1]) i++;

            if(i == peak) {
                i++;
                continue;
            }

            res = max(res, i - temp + 1);
        }

        return res;
    }
};
