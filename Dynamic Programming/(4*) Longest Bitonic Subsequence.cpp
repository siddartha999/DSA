/**
* Problem Link: https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
* Reference: https://www.youtube.com/watch?v=y4vN0WNdrlg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=49
**/

// TC: O(N^2), SC: O(N)
int LongestBitonicSequence(vector<int>nums)
	{
	    vector<int> lis(nums.size(), 1);
	    vector<int> lds(nums.size(), 1);
	    
	    for(int idx = 1; idx < nums.size(); idx++) {
	        for(int j = 0; j < idx; j++) {
	            if(nums[idx] > nums[j]) {
	                lis[idx] = max(lis[idx], 1 + lis[j]);
	            }
	        }
	    }
	    
	    for(int idx = nums.size() - 2; idx >= 0; idx--) {
	        for(int j = idx + 1; j < nums.size(); j++) {
	            if(nums[idx] > nums[j]) {
	                lds[idx] = max(lds[idx], 1 + lds[j]);
	            }
	        }
	    }
	    
	    int bitonicLength = 0;
	    for(int idx = 0; idx < nums.size(); idx++) {
	        bitonicLength = max(bitonicLength, lis[idx] + lds[idx] - 1);
	    }
	    
	    return bitonicLength;
	}
