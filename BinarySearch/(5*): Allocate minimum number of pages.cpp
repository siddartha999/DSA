/**
* Problem Link: https://leetcode.com/problems/split-array-largest-sum/description/
* Problem Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
* Reference: https://www.youtube.com/watch?v=Z0hwjftStI4&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=19 ;
https://www.youtube.com/watch?v=2JSQIhPcHQg&t=264s
**/

// TC: O(n * log(sum - maxVal)), SC: O(1)
//A rule of thumb: To minimize the maximum value, the items in the list should be close by i.e, the distribution should not burden one item with everything. 
class Solution 
{
  public:
    int findPages(int A[], int N, int M) 
    {
        if(M > N) return -1;
        int maxVal = A[0], sum = 0;
        for(int i = 0; i < N; i++) {
            if(maxVal < A[i]) maxVal = A[i];
            sum += A[i];
        }
        int left = maxVal, right = sum;
        int res = sum;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(countStudents(A, N, M, mid) > M) {
                left = mid + 1;
            }
            else {
                res = mid;
                right = mid - 1;
            }
        }
        return res;
    }
    
   private:
        int countStudents(int A[], int& N, int& M, int maxPages) {
            int students = 1;
            int countSoFar = 0;
            for(int idx = 0; idx < N; idx++) {
                countSoFar += A[idx];
                if(countSoFar > maxPages) {
                    students++;
                    countSoFar = A[idx];
                }
            }
            return students;
        }
};
