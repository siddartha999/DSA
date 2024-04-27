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










// Approach 3: Binary Search. TC: O(min(log(n), log(m))), SC: O(1)
class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size()) {
            return MedianOfArrays(nums2, nums1);
        }
        
        int left = 0, right = nums1.size();
        int leftBucketSize = (nums1.size() + nums2.size()) / 2;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int leftOneIdx = mid - 1;
            int leftTwoIdx = leftBucketSize - mid - 1;
            int leftOneVal = (leftOneIdx == -1) ? INT_MIN : nums1[leftOneIdx];
            int leftTwoVal = (leftTwoIdx == -1) ? INT_MIN : nums2[leftTwoIdx];
            int rightOneVal = (leftOneIdx + 1 >= nums1.size()) ? INT_MAX : nums1[leftOneIdx + 1];
            int rightTwoVal = (leftTwoIdx + 1 >= nums2.size()) ? INT_MAX : nums2[leftTwoIdx + 1];
            
            if(leftOneVal <= rightTwoVal && leftTwoVal <= rightOneVal) {
                if( (nums1.size() + nums2.size()) % 2 == 0) { //EVEN
                    return (double)(max(leftOneVal, leftTwoVal) + min(rightOneVal, rightTwoVal)) / 2;
                }
                else { //ODD
                    return min(rightOneVal, rightTwoVal);
                }
            }
            else if(leftOneVal > rightTwoVal) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
    }
};

