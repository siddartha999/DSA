/**
* Problem Link: https://www.geeksforgeeks.org/problems/rotation4723/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
**/

// TC: O(logN), SC: O(1)
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int left = 0, right = n - 1;
	    int minVal = INT_MAX, minIdx = n;
	   
      while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= nums[left] && nums[mid] <= nums[right]) {
                if(minVal > nums[left]) {
                    minVal = nums[left];
                    minIdx = left;
                }
                break;
            }
            else if(nums[mid] <= nums[right]) {
                if(minVal > nums[mid]) {
                    minVal = nums[mid];
                    minIdx = mid;
                }
                right = mid - 1;
            }
            else {
                if(minVal > nums[left]) {
                    minVal = nums[left];
                    minIdx = left;
                }
                left = mid + 1;
            }
        }
	    
	    return minIdx;
	}

};
