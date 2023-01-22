/**
* Link: https://leetcode.com/problems/merge-k-sorted-lists/description/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(ListNode* node: lists) {
            if(node != NULL) pq.push({node->val, node});
        }

        ListNode* sentinelHead = new ListNode(-999);
        ListNode* temp = sentinelHead;

        while(!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();
            if(node->next) pq.push({node->next->val, node->next});
            node->next = NULL;
            temp->next = node;
            temp = temp->next;
        }

        return sentinelHead->next;
    }
};

//TC: O(N), SC: O(1)
