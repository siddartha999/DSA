/**
* Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
*/

// Approach 1: TC: O(N), SC: O(2 * H)

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> qq;
        qq.push(root);
        while(qq.size()) {
            int size = qq.size();
            Node* prev = NULL;
            while(size--) {
                Node* node = qq.front();
                qq.pop();
                node->next = prev;
                prev = node;
                if(node->right) {
                    qq.push(node->right);
                }
                if(node->left) {
                    qq.push(node->left);
                }
            }
        }
        return root;
    }
};


// Approach 2: TC:O(N), SC: O(1). Taking advantage of the perfect binary tree property!

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* temp = root;
        while(temp && temp->left) {
            Node* nextLevelStart = temp->left;
            while(temp) {
                temp->left->next = temp->right;
                if(temp->next) {
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            temp = nextLevelStart;
        }
        return root;
    }
};
