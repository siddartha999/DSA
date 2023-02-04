/**
* Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/

//Approach 1: TC: O(N), SC: O(N)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> cache;
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            cache[temp] = newNode;
            temp = temp->next;
        }
        //Reset
        temp = head;

        while(temp) {
            Node* random = temp->random;
            if(random)cache[temp]->random = cache[random];
            if(temp->next) cache[temp]->next = cache[temp->next];
            temp = temp->next;
        }

        Node* newHead = cache[head];
        return newHead;
    }
};

//Approach 2: TC: O(N), SC: O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp = head;
        Node* newHead = NULL;
        //Copy Nodes
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        //Append random pointers
        temp = head;
        while(temp) {
            Node* random = temp->random;
            if(random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        //Distinguish the original & copied nodes
        temp = head;
        newHead = temp->next;
        while(temp) {
            Node* next = temp->next->next;
            if(next) temp->next->next = next->next;
            temp->next = next;
            temp = next;
        }
        return newHead;
    }
};
