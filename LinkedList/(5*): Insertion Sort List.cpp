/**
* Link: https://leetcode.com/problems/insertion-sort-list/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* sentinelHead = new ListNode(-999, head);
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp) {
            if(prev->val > temp->val) {
                ListNode* node = sentinelHead->next;
                ListNode* prevNode = sentinelHead;
                while(node->val < temp->val) {
                    prevNode = node;
                    node = node->next;
                }
                ListNode* tempNext = temp->next;
                prevNode->next = temp;
                temp->next = node;
                prev->next = tempNext;
                temp = tempNext;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return sentinelHead->next;
    }
};

// TC: O(N^2), SC: O(1)
