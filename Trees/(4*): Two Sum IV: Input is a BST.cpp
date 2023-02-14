/*
* Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
* Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

* NOTE: Practice BST iterator problem first.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class TreeIterator {
private:
    stack<TreeNode*> stack;
    bool isReverse;
    TreeNode* node;
public:
    TreeIterator(TreeNode* root, bool reverseTraversal) {
        node = root;
        isReverse = reverseTraversal;
    }
    int next() {
        while(node) {
            stack.push(node);
            if(isReverse) node = node->right;
            else node = node->left;
        }
        node = stack.top();
        stack.pop();
        int val = node->val;
        if(isReverse) node = node->left;
        else node = node->right;
        return val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        TreeIterator* leftIterator = new TreeIterator(root, false);
        TreeIterator* rightIterator = new TreeIterator(root, true);
        int leftVal = leftIterator->next();
        int rightVal = rightIterator->next();
        while(leftVal < rightVal) {
            int sum = leftVal + rightVal;
            if(sum == k) return true;
            if(sum > k) {
                rightVal = rightIterator->next();
            }
            else {
                leftVal = leftIterator->next();
            }
        }
        return false;
    }
};
