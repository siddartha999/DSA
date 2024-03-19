/**
* https://leetcode.com/problems/koko-eating-bananas/description/
* Reference: https://www.youtube.com/watch?v=qyfekrNni90&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=13
* Useful Reference: https://leetcode.com/problems/koko-eating-bananas/solutions/769702/python-clear-explanation-powerful-ultimate-binary-search-template-solved-many-problems/
**/

// TC: O(N) * O(log(maxElement))
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minVal = 1, maxVal = piles[0];
        for(int pile: piles) {
            minVal = min(minVal, pile);
            maxVal = max(maxVal, pile);
        }

        int left = minVal, right = maxVal;
        int res = maxVal;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            long long sumHours = 0;
            for(int pile: piles) {
                sumHours += (pile / mid) + (pile % mid != 0 ? 1 : 0);
            }
            if(sumHours > h) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
                res = min(res, mid);
            }
        }

        return res;
    }
};
