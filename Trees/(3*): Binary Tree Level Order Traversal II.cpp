/**
* Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
**/

//TC: O(N), SC: O(N)
vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty()) {
            int size = qq.size();
            vector<int> row;
            while(size--) {
                TreeNode* node = qq.front();
                qq.pop();
                row.push_back(node->val);
                if(node->left) {
                    qq.push(node->left);
                }
                if(node->right) {
                    qq.push(node->right);
                }
            }
            res.push_back(row);
        }

        for(int idx = 0; idx < res.size() / 2; idx++) {
            int leftIdx = idx;
            int rightIdx = res.size() - idx - 1;
            vector<int> temp = res[leftIdx];
            res[leftIdx] = res[rightIdx];
            res[rightIdx] = temp;
        }

        return res;
    }
