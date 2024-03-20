/**
* Problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
**/

// TC: O(N * (count - maxVal + 1)), SC: O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1;
        int sum = 0;
        for(int weight: weights) {
            left = max(left, weight);
            sum += weight;
        }
        int right = sum;
        int res = sum;
        while(left <= right) {
            int maxWeight = left + (right - left) / 2;
            int estimatedDays = 1;
            int currentWeight = 0;
            for(int weight: weights) {
                if(currentWeight + weight > maxWeight) {
                    estimatedDays++;
                    currentWeight = 0;
                }
                currentWeight += weight;
            }
            if(estimatedDays <= days) {
                res = maxWeight;
                right = maxWeight - 1;
            }
            else {
                left = maxWeight + 1;
            }
        }
        return res;
    }
};
