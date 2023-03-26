/**
* Link: https://leetcode.com/problems/increasing-order-search-tree/description/
*/

// Approach 1 => TC: O(N), SC: O(H)
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = NULL;
        helper(root, prev);
        return prev; 
    }
private:
    void helper(TreeNode* root, TreeNode*& prev) {
        if(!root) return;
        helper(root->right, prev);
        root->right = prev;
        prev = root;
        helper(root->left, prev);
        root->left = NULL;
    }
};


// Approach 2: TC:O(N), SC: O(H). 
// An intelligent solution https://leetcode.com/problems/increasing-order-search-tree/solutions/165885/c-java-python-self-explained-5-line-o-n/
// result = inorder(root.left) + root + inorder(root.right)

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root, NULL);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* nextNodeInInorder) {
        if(!root) return nextNodeInInorder;
        TreeNode* res = helper(root->left, root); // Current root would be the next node for its left Child in inorder
        root->left = NULL;
        root->right = helper(root->right, nextNodeInInorder); // nextNodeInInorder would be the next node for right child in inorder
        return res;
    }
};
