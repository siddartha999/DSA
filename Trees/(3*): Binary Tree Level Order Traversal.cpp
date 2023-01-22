/**
* Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> temp;
            while(size--) {
                TreeNode* node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                if(node->left) {
                    queue.push(node->left);
                }
                if(node->right) {
                    queue.push(node->right);
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};

// TC: O(N), SC: O(N)
