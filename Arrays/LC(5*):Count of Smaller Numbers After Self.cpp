/**
* Problem: Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i]
* Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
*/

//Approach 1: BST. TC: O(N^2), worst case BST gets skewed to the either side

class BST {
private:
    BST* leftNode;
    BST* rightNode;
    int leftCount;
    int val;
public:
    BST(int _val, int _leftCount) {
        val = _val;
        leftCount = _leftCount;
        leftNode = NULL;
        rightNode = NULL;
    };
    int getVal() {
        return this->val;
    }
    void setLeftNode(BST* node) {
        this->leftNode = node;
    }
    void setRightNode(BST* node) {
        this->rightNode = node;
    }
    void incrementLeftCount(int freq) {
        this->leftCount += freq;
    }
    BST* getLeftNode() {
        return this->leftNode;
    }
    BST* getRightNode() {
        return this->rightNode;
    }
    int getLeftCount() {
        return this->leftCount;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        BST* root = NULL;
        for(int i = nums.size() - 1; i >= 0; i--) {
            root = helper(root, nums[i], 0, res, i);
        }
        return res;
    }
private:
    BST* helper(BST* root, int val, int count, vector<int>& res, int& idx) {
        if(!root) {
            res[idx] = count;
            return new BST(val, 0);
        }
        if(root->getVal() >= val) {
            BST* node = helper(root->getLeftNode(), val, count, res, idx);
            root->setLeftNode(node);
            root->incrementLeftCount(1);
        }
        else {
            BST* node = helper(root->getRightNode(), val, count + root->getLeftCount() + 1, res, idx);
            root->setRightNode(node);
        }
        return root;
    }
};



//Approach 2: MergeSort. TC: O(NlogN)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<pair<int, int>> newNums(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            newNums[i] = {nums[i], i};
        }
        mergeSort(newNums, 0, newNums.size() - 1, res);
        return res;
    }
private:    
    void mergeSort(vector<pair<int, int>>& nums, int left, int right, vector<int>& res) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, res);
        mergeSort(nums, mid + 1, right, res);
        merge(nums, left, mid, right, res);
    }
    void merge(vector<pair<int, int>>& nums, int left, int mid, int right, vector<int>& res) {
        int ll = left;
        int rr = mid + 1;
        vector<pair<int, int>> temp(right - left + 1);
        int tempIdx = 0;
        while(ll <= mid && rr <= right) {
            if(nums[ll].first > nums[rr].first) {
                res[nums[ll].second] += right - rr + 1;
                temp[tempIdx++] = nums[ll++];
            }
            else {
                temp[tempIdx++] = nums[rr++];
            }
        }
        while(ll <= mid) {
            temp[tempIdx++] = nums[ll++];
        }
        while(rr <= right) {
            temp[tempIdx++] = nums[rr++];
        }
        tempIdx = 0;
        for(int idx = left; idx <= right; idx++) {
            nums[idx] = temp[tempIdx++];
        }
    }
};
