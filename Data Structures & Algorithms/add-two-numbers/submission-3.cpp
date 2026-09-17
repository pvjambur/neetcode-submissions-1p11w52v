class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int car = 0;

        while(l1 || l2 || car){
            int sum = car;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            cur->next = new ListNode(sum%10);
            cur = cur->next;
            car = sum/10;
        }

        return dummy->next;
    }
};