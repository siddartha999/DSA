/**
* Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
* Reference: https://youtu.be/C2rRzz-JDk8?si=M6gjzcr62vUdNao5
* Reference: https://www.youtube.com/watch?v=F9c7LpRZWVQ&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=23
**/

// Approach 1: Brute Force. TC: O(N + M), SC: O(N + M)
class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> combinedList;
        int idx1 = 0, idx2 = 0;
        
        while(idx1 < nums1.size() && idx2 < nums2.size()) {
            if(nums1[idx1] < nums2[idx2]) {
                combinedList.push_back(nums1[idx1]);
                idx1++;
            }
            else {
                combinedList.push_back(nums2[idx2]);
                idx2++;
            }
        }
        while(idx1 < nums1.size()) {
            combinedList.push_back(nums1[idx1]);
            idx1++;
        }
        while(idx2 < nums2.size()) {
            combinedList.push_back(nums2[idx2]);
            idx2++;
        }
        
        int size = combinedList.size();
        if(size % 2 == 0) {
            int leftVal = combinedList[(size / 2) - 1];
            int rightVal = combinedList[size / 2];
            return ((double)leftVal + rightVal) / 2;
        }
        
        return combinedList[size / 2];
    }
};










// Approach 2: Enhanced Brute Force. TC: O(N + M), SC: O(1)
class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int idx1 = 0, idx2 = 0;
        int medianIdx = (nums1.size() + nums2.size()) / 2;
        int prevMedianIdx = (nums1.size() + nums2.size()) / 2 - 1;
        int ans1 = -1, ans2 = -1;
        
        while(idx1 < nums1.size() && idx2 < nums2.size()) {
            if(nums1[idx1] < nums2[idx2]) {
                if(idx1 + idx2 == prevMedianIdx) {
                    ans1 = nums1[idx1];
                }
                else if(idx1 + idx2 == medianIdx) {
                    ans2 = nums1[idx1];
                }
                idx1++;
            }
            else {
                if(idx1 + idx2 == prevMedianIdx) {
                    ans1 = nums2[idx2];
                }
                else if(idx1 + idx2 == medianIdx) {
                    ans2 = nums2[idx2];
                }
                idx2++;
            }
            
        }
        while(idx1 < nums1.size()) {
            if(idx1 + idx2 == prevMedianIdx) {
                ans1 = nums1[idx1];
            }
            else if(idx1 + idx2 == medianIdx) {
                ans2 = nums1[idx1];
            }
            idx1++;
        }
        while(idx2 < nums2.size()) {
            if(idx1 + idx2 == prevMedianIdx) {
                ans1 = nums2[idx2];
            }
            else if(idx1 + idx2 == medianIdx) {
                ans2 = nums2[idx2];
            }
            idx2++;
        }
        
        if((nums1.size() + nums2.size()) % 2 == 0) {
            return ((double)ans1 + ans2) / 2;
        }
        return ans2;
    }
};










// Approach 3: Binary Search

