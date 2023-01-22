/**
* Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* getLastChildNode(Node* head) {
        while(head->next != NULL) head = head->next;
        return head;
    }
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* temp = head;
        while(temp) {
            if(temp->child) {
                Node* lastChildNode = getLastChildNode(temp->child);
                lastChildNode->next = temp->next;
                //Condition Check
                if(temp->next) temp->next->prev = lastChildNode;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            }
            temp = temp->next;
        }
        return head;
    }
};

//TC: O(N), SC: O(1)
