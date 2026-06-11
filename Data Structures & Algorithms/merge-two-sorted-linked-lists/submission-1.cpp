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
        if (!list1 && !list2) return NULL;
        else if (!list1) return list2;
        else if (!list2) return list1;

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while (cur1!=NULL && cur2!=NULL){
            if (cur1->val<cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else{
                cur->next = cur2;
                cur2 = cur2->next;
            }

            cur = cur->next;

        }

        if (cur1==NULL && cur2==NULL){
            cur->next = NULL;
        }
        else if (cur1==NULL){
            cur->next = cur2;
        }
        else{
            cur->next = cur1;
        }

        return head->next;
        

    }
};
