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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        while (head!=NULL && head->val==val){
            head = head->next;
        }
        if (!head) return head;
        ListNode* cur = head->next;
        ListNode* prev = head;
        while (cur!=NULL){
            while (cur!=NULL && cur->val==val) cur=cur->next;
            prev->next = cur;
            prev = cur;
            if (cur!=NULL) cur = cur->next;
        }
        return head;
    }
};