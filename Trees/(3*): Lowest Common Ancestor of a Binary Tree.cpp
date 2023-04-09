/**
* Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
* TBD far in to the future: Iterative solution. Don't think this is necessary though, but should be a fun exercise
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root; //CASE 1
        TreeNode* leftTraversal = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTraversal = lowestCommonAncestor(root->right, p, q);
        if(leftTraversal && rightTraversal) { //CASE 2
            return root;
        }
        if(leftTraversal || rightTraversal) { //CASE 3
            return leftTraversal != NULL ? leftTraversal : rightTraversal;
        }
        return NULL;
    }
};

// TC: O(N), SC: O(N). Worst scenario: skewed-tree
