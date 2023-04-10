/**
* Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
* Brilliant Iterative solution Viz: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/1347857/c-java-python-iterate-in-bst-picture-explain-time-o-h-space-o-1/?orderBy=most_votes
*/

// O(N) for BST in the worst case i.e left or right skewed trees

// Approach 1: Recursive, TC: O(N), SC: O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int minVal = min(p->val, q->val);
        int maxVal = max(p->val, q->val);
        if(root->val >= minVal && root->val <= maxVal) { // CASE 1
            return root;
        }
        if(root->val > p->val && root->val > q->val) { // CASE 2
            return lowestCommonAncestor(root->left, p, q);
        }
        //CASE 3
        return lowestCommonAncestor(root->right, p, q);
    }
};


// Approach 2: Iterative, TC: O(N), SC: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int minVal = min(p->val, q->val);
        int maxVal = max(p->val, q->val);
        while(root) {
            if(root->val >= minVal && root->val <= maxVal) return root; // CASE 1
            if(root->val >= minVal && root->val >= maxVal) root = root->left; // CASE 2
            else root = root->right; // CASE 3
        }
        return NULL;
    }
};
