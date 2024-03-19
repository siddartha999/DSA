/**
* Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
**/

// TC: O(N * log(maxValue)), SC: O(1)
class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        long long requiredFlowers = (long long)m * k;
        if(requiredFlowers > nums.size()) return -1;

        //Sort and list the unique days
        set<int> sortedSet;
        for(int num: nums) sortedSet.insert(num);
        vector<int> sortedList;
        for(auto it = sortedSet.begin(); it != sortedSet.end(); it++) {
            sortedList.push_back(*it);
        }

        int left = 0, right = sortedList.size() - 1;
        int res = INT_MAX;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int day = sortedList[mid];
            int bouquetCount = 0;
            int currentCount = 0;
            for(int num: nums) {
                if(num <= day) {
                    currentCount++;
                    if(currentCount == k) {
                        bouquetCount++;
                        currentCount = 0;
                    }
                    if(bouquetCount == m) {
                        res = day;
                        break;
                    }
                }
                else {
                    currentCount = 0;
                }
            }

            if(bouquetCount == m) { //Success
                right = mid - 1;
            }
            else { //Failure
                left = mid + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
