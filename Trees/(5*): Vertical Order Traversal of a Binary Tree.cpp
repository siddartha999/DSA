/**
* Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
* Prefer a iterative BFS approach. TC: O(NlogN), SC: O(N) 
*/

class TreeNodeObj {
    int row;
    int val;
public:
    TreeNodeObj(int _row, int _val) {
        row = _row;
        val = _val;
    }
    static bool comparator(TreeNodeObj* a, TreeNodeObj* b) {
        if(a->row < b->row) return true;
        if(a->row > b->row) return false;

        if(a->val < b->val) return true;
        return false;
    }
    int getValue() {
        return val;
    }
};

class TreeNodePair {
    TreeNode* node;
    int row;
    int col;
public:
    TreeNodePair(TreeNode* _node, int _row, int _col) {
        node = _node;
        row = _row;
        col = _col;
    }
    TreeNode* getNode() {
        return node;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int row = 0, col = 0;
        map<int, vector<TreeNodeObj*>> map;
        queue<TreeNodePair*> pq;
        pq.push(new TreeNodePair(root, 0, 0));
        while(!pq.empty()) {
            int size = pq.size();
            while(size--) {
                TreeNodePair* tnp = pq.front();
                pq.pop();
                int row = tnp->getRow();
                int col = tnp->getCol();
                TreeNode* node = tnp->getNode();;
                vector<TreeNodeObj*> vec;
                if(map[col].size() > 0) vec = map[col];
                vec.push_back(new TreeNodeObj(row, node->val));
                map[col] = vec;

                if(node->left) {
                    pq.push(new TreeNodePair(node->left, row + 1, col - 1));
                }
                if(node->right) {
                    pq.push(new TreeNodePair(node->right, row + 1, col + 1));
                }
            }
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            vector<TreeNodeObj*> vec = map[it->first];
            sort(vec.begin(), vec.end(), TreeNodeObj::comparator);

            vector<int> ret;
            for(int i = 0; i < vec.size(); i++) {
                ret.push_back(vec[i]->getValue());
            }

            res.push_back(ret);
        }

        return res;
    }
};
