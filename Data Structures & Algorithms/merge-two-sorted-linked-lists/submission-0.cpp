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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while (cur1!=NULL && cur2!=NULL){
            if (cur1->val>=cur2->val){
                temp->next=cur2;
                temp = cur2;
                cur2=cur2->next;
            }
            else{
                temp->next=cur1;
                temp = cur1;
                cur1=cur1->next;
            }
        }
        if (cur1!=NULL) temp->next=cur1;
        if (cur2!=NULL) temp->next=cur2;
        return head->next;
    }
};
