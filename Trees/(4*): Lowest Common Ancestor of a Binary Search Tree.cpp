/**
* Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
* Brilliant Iterative solution Viz: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/1347857/c-java-python-iterate-in-bst-picture-explain-time-o-h-space-o-1/?orderBy=most_votes
*/

// Approach 1: Recursive, TC: O(H), SC: O(H)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root; // Case 1
        TreeNode* leftTraversal = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTraversal = lowestCommonAncestor(root->right, p, q);
        if(leftTraversal && rightTraversal) { // Case 2
            return root;
        }
        if(leftTraversal || rightTraversal) { // Case 3
            return leftTraversal != NULL ? leftTraversal : rightTraversal;
        }
        return NULL;
    }
};


// Approach 2: Iterative, TC: O(H), SC: O(1)
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
