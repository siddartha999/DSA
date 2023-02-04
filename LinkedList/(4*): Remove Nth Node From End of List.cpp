/**
* Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/

// Approach 1: TC: O(N), SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinelHead = new ListNode(-999, head);
        int length = 0;
        ListNode* temp = head;
        //Figre out the length of the list
        while(temp) {
            length++;
            temp = temp->next;
        }
        ListNode* prev = sentinelHead;
        temp = head;
        int targetNode = length - n;
        //Land up on the target node
        while(targetNode--) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return sentinelHead->next;
    }
};



//Approach 2: TC:O(N), SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinelHead = new ListNode(-999, head);
        ListNode* fast = head;
        while(n--) {
            fast = fast->next;
        }
        ListNode* slow = sentinelHead;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next ? slow->next->next : NULL;
        return sentinelHead->next;
    }
};
