/*
  *Problem: https://leetcode.com/problems/binary-search-tree-iterator/description/
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
class BSTIterator {
private:
    stack<TreeNode*> stack;
    TreeNode* node;
public:
    BSTIterator(TreeNode* root) {
        node = root;
    }
    
    int next() {
        while(node) {
            stack.push(node);
            node = node->left;
        }
        node = stack.top();
        stack.pop();
        int val = node->val;
        node = node->right;
        return val;
    }
    
    bool hasNext() {
        return node != NULL || !stack.empty();
    }
};
