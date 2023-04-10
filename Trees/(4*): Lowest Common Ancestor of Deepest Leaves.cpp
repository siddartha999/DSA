/**
* Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
*/

// TC: O(N), SC: O(H)

class DepthNode {
    int depth;
    TreeNode* node;
public:
    DepthNode(int _depth, TreeNode* _node) {
        depth = _depth;
        node = _node;
    }
    int getDepth() {
        return depth;
    }
    void incrementDepth() {
        depth += 1;
    }
    TreeNode* getNode() {
        return node;
    }
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        DepthNode* node = findLCA(root);
        return node->getNode();
    }

private:
    DepthNode* findLCA(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left && !root->right) {
            return new DepthNode(1, root);
        }

        DepthNode* left = findLCA(root->left);
        DepthNode* right = findLCA(root->right);

        if(!left || !right) {
            if(left != NULL) {
                left->incrementDepth();
                return left;
            }
            right->incrementDepth();
            return right;
        }

        if(left->getDepth() == right->getDepth()) {
            return new DepthNode(1 + left->getDepth(), root);
        }
        
        if(left->getDepth() > right->getDepth()) {
            left->incrementDepth();
            return left;
        }
        right->incrementDepth();
        return right;
    }
};
