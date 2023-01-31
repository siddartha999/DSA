/**
* Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
* A tricky one! Must practice!
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* sentinelHead = new ListNode(-999, head);
        ListNode* prev = sentinelHead;
        ListNode* current = head;
        while(current && current->next) {
            if(current->val == current->next->val) {
                while(current->next && current->val == current->next->val) current = current->next;
                prev->next = current->next;
            }
            else {
                prev = current;
            }
            current = current->next;
        }
        return sentinelHead->next;
    }
};

// TC: O(N), SC: O(1)
