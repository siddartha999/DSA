/**
* Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
*/

// Approach 1: TC: O(N), SC: O(2 * H)

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> qq;
        qq.push(root);
        while(!qq.empty()) {
            int size = qq.size();
            Node* prev = NULL;
            while(size--) {
                Node* temp = qq.front();
                qq.pop();
                temp->next = prev;
                prev = temp;
                if(temp->right) qq.push(temp->right);
                if(temp->left) qq.push(temp->left);
            }
        }
        return root;
    }
};


// Approach 2: TC: O(N), SC: O(1). Dummy node at each level to overcome the limitation of not having the luxury of the Perfect Binary Tree property
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* temp = root;
        while(temp) {
            Node* dummyNode = new Node(-999);
            Node* dummyNodePtr = dummyNode;
            while(temp) {
                if(temp->left) {
                    dummyNodePtr->next = temp->left;
                    dummyNodePtr = dummyNodePtr->next;
                }
                if(temp->right) {
                    dummyNodePtr->next = temp->right;
                    dummyNodePtr = dummyNodePtr->next;
                }
                temp = temp->next;
            }
            temp = dummyNode->next;
        }
        return root;
    }
};
