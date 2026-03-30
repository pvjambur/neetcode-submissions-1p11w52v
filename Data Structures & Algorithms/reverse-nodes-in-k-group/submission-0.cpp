class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        
        while (cur != NULL){
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode* cur = head;
        int count = 0;

        while (cur && count < k){
            cur = cur->next;
            count++;
        }

        if (count < k) return head;

        ListNode* prev = NULL;
        cur = head;
        count = 0;

        while (cur && count < k){
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
            count++;
        }
        head->next = reverseKGroup(cur, k);

        return prev;
    }
};