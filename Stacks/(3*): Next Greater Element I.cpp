/**
* Link: https://leetcode.com/problems/next-greater-element-i/description/
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cache;
        stack<int> stack;
        for(int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];
            while(!stack.empty() && num > nums2[stack.top()]) {
                cache[nums2[stack.top()]] = num;
                stack.pop();
            }
            stack.push(i);
        }
      
        vector<int> res(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            if(cache.find(num) != cache.end()) res[i] = cache[num];
        }
        return res;
    }
};

//TC: O(N + M), SC: O(M)
