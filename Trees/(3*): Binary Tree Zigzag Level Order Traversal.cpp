/**
* Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stack1, stack2;
        stack1.push(root);
        vector<vector<int>> res;
        bool isLeftToRight = true;
      
        while(!stack1.empty() || !stack2.empty()) {
            int size = isLeftToRight == true ? stack1.size() : stack2.size();
            vector<int> temp;
          
            while(size--) {
                TreeNode* node;
                if(isLeftToRight == true) {
                    node = stack1.top();
                    stack1.pop();
                    if(node->left) stack2.push(node->left);
                    if(node->right) stack2.push(node->right);
                }
                else {
                    node = stack2.top();
                    stack2.pop();
                    if(node->right) stack1.push(node->right);
                    if(node->left) stack1.push(node->left);
                }
                temp.push_back(node->val);
            }
          
            res.push_back(temp);
            isLeftToRight = !isLeftToRight;
        }

        return res;
    }
};

// TC: O(N), SC: O(N)
