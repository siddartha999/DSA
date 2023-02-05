/**
* Link: https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

// Approach 1: TC: O(N^2), SC: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};




// Approach 2: Prefix Sum. TC: O(N), SC: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cache;
        cache[0] = 1;
        int sum = 0;
        int count = 0;
        for(int num: nums) {
            sum += num;
            if(cache.find(sum - k) != cache.end()) {
                count += cache[sum - k];
            }
            cache[sum]++; //Can't place this statement above the cache condition
            // as a prefix sum is required to calculate the count
        }
        return count;
    }
};

