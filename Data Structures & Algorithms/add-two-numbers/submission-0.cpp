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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *c1=l1, *c2=l2;
        ListNode* res = new ListNode();
        ListNode* c3 = res;
        int carry = 0;
        while (c1!=NULL && c2!=NULL){
            ListNode* temp = new ListNode(0);
            temp->val = (int)(carry + c1->val + c2->val);
            carry = (temp->val)/10;
            temp->val %= 10;
            c3->next = temp;
            c3 = temp;
            c1 = c1->next;
            c2 = c2->next;
        }

        while (c1!=NULL){
            ListNode* temp = new ListNode(0);
            temp->val = carry + c1->val;
            carry = (temp->val)/10;
            temp->val %= 10;
            c3->next = temp;
            c3 = temp;
            c1 = c1->next;
        }

        while (c2!=NULL){
            ListNode* temp = new ListNode(0);
            temp->val = carry + c2->val;
            carry = (temp->val)/10;
            temp->val %= 10;
            c3->next = temp;
            c3 = temp;
            c2 = c2->next;
        }

        if (carry>0){
            ListNode* temp = new ListNode(0);
            temp->val = carry;
            c3->next = temp;
            c3 = temp;
        }

        return res->next;
    }
};
