/**
* Problem Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
**/

//TC: O(log(min(n, m))), SC: O(1)
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m) {
            return kthElement(arr2, arr1, m, n, k);
        }
        
        int left = max(0, k - m), right = min(k, n);
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int leftOneIdx = mid - 1;
            int leftTwoIdx = k - mid - 1;
            int leftOneVal = (leftOneIdx < 0) ? INT_MIN : arr1[leftOneIdx];
            int leftTwoVal = (leftTwoIdx < 0) ? INT_MIN : arr2[leftTwoIdx];
            int rightOneVal = (leftOneIdx + 1 >= n) ? INT_MAX : arr1[leftOneIdx + 1];
            int rightTwoVal = (leftTwoIdx + 1 >= m) ? INT_MAX : arr2[leftTwoIdx + 1];
            if(leftOneVal <= rightTwoVal && leftTwoVal <= rightOneVal) {
                return max(leftOneVal, leftTwoVal);
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
