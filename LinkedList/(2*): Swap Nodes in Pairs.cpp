/**
* Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* sentinelHead = new ListNode(-999, head);
        ListNode* prev = sentinelHead;
        ListNode* curr = head;
        while(curr && curr->next) {
            ListNode* nextNext = curr->next->next;
            prev->next = curr->next;
            prev->next->next = curr;
            curr->next = nextNext;
            prev = curr;
            curr = nextNext;
        }
        return sentinelHead->next;
    }
};

//TC: O(N), SC: O(1)
