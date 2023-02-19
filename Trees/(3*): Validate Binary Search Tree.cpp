/**
* Link: https://leetcode.com/problems/validate-binary-search-tree/description/
* NOTE: Prefer the iterative versions of Pre / In / Post order traversals
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        stack<TreeNode*> stack;
        TreeNode* prevNode = NULL;
        while(root || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(prevNode && prevNode->val >= root->val) {
                return false;
            }
            prevNode = root;
            root = root->right;
        }
        return true;
    }
};


// TC: O(N), SC: O(H)
