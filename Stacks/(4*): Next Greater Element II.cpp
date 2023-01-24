/**
* Link: https://leetcode.com/problems/next-greater-element-ii/description/
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stack;
        int size = nums.size();
        for(int i = 0; i < 2 * size; i++) {
            int num = nums[i % size];
            while(!stack.empty() && num > nums[stack.top()]) {
                res[stack.top()] = num;
                stack.pop();
            }
            if(i < size) stack.push(i);
        }
        return res;
    }
};

//TC: O(N), SC: O(N)
