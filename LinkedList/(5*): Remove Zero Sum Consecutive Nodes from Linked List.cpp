/**
* Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        ListNode* sentinelHead = new ListNode(-999, head);
        unordered_map<int, ListNode*> cache;
        cache[0] = sentinelHead;
        int sum = 0;
        ListNode* temp = head;
        while(temp) {
            sum += temp->val;
            if(cache.find(sum) != cache.end()) {
                ListNode* start = cache[sum]->next;
                int val = sum;
                while(start != temp) {
                    val += start->val;
                    cache.erase(val);
                    start = start->next;
                }
                cache[sum]->next = temp->next;
            }
            else {
                cache[sum] = temp;
            }
            temp = temp->next;
        }
        return sentinelHead->next;
    }
};

// TC: O(N),SC: O(N)
