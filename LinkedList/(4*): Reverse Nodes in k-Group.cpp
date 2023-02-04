/**
* Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        ListNode* sentinelHead = new ListNode(-999, head);
        ListNode* prev = sentinelHead;
        ListNode* temp = head;
        while(temp) {
            int val = k;
            while(temp && val > 1) {
                temp = temp->next;
                val--;
            }
            if(temp == NULL && val >= 1) break;
            ListNode* tempNext = temp ? temp->next : NULL;
            ListNode* prevNext = prev->next;
            if(temp) temp->next = NULL;
            prev->next = NULL;
            reverse(prevNext);
            prev->next = temp;
            prev = prevNext;
            prevNext->next = tempNext;
            if(temp) temp = tempNext;
        }
        return sentinelHead->next;
    }
  
    void reverse(ListNode* head) {
        ListNode* prevNode = NULL, *nextNode = NULL;
        while(head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
    }
};

// TC: O(N), SC: O(1)
