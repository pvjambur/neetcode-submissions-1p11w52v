class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next) return head;

        int count = 1;
        ListNode* cur = head;

        while (cur->next) {
            cur = cur->next;
            count++;
        }

        cur->next = head; 

        k = k % count;
        int steps = count - k;

        ListNode* new_tail = cur;

        while (steps--) {
            new_tail = new_tail->next;
        }

        ListNode* new_head = new_tail->next;
        new_tail->next = NULL;

        return new_head;
    }
};