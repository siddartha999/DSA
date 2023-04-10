/**
* Link: https://leetcode.com/problems/invert-binary-tree/description/
*/

// Approach 1: Basic Recursion. TC: O(N), SC: O(N). Worst case: skewed tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;

        TreeNode* leftSubtree = invertTree(root->left);
        TreeNode* rightSubtree = invertTree(root->right);

        root->left = rightSubtree;
        root->right = leftSubtree;

        return root;
    }
};

// Approach 2: Iterative recursion with Stack. TC: O(N), SC: O(N)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;

        stack<TreeNode*> stack;
        TreeNode* node = root;

        while(node || !stack.empty()) {
            while(node) {
                stack.push(node);
                node = node->left;
            }
            node = stack.top();
            stack.pop();

            TreeNode* leftNode = node->left;
            TreeNode* rightNode = node->right;
            node->left = rightNode;
            node->right = leftNode;
            node = rightNode;
        }

        return root;
    }
};


// Approach 3: Level order traversal. TC: O(N), SC: O(N)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;

        queue<TreeNode*> qq;
        qq.push(root);

        while(!qq.empty()) {
            int size = qq.size();
            while(qq.size()) {
                TreeNode* node = qq.front();
                qq.pop();

                TreeNode* leftNode = node->left;
                TreeNode* rightNode = node->right;

                node->left = rightNode;
                node->right = leftNode;

                if(leftNode) qq.push(leftNode);
                if(rightNode) qq.push(rightNode);
            }
        }

        return root;
    }
};
