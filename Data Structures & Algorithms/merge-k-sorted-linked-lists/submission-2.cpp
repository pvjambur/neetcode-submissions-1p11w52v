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
        priority_queue<ListNode*,vector<ListNode*>,function<bool(ListNode*,ListNode*)>> pq([](ListNode* a, ListNode* b){
            return a->val > b->val;
        });

        for (auto node: lists){
            if (node) pq.push(node);
        }

        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (!pq.empty()){
            ListNode* cur1 = pq.top();
            pq.pop();
            cur->next = cur1;
            cur = cur->next;

            if (cur1->next) pq.push(cur1->next);
        }
        cur->next = NULL;
        return head->next;
    }
};
