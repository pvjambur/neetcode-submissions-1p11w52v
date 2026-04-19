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
private:
    ListNode* reverse(ListNode* node){
        ListNode* prev;
        while (node!=NULL){
            ListNode* temp = node->next;
            node->next = prev;
            prev=node;
            node=temp;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l;
        ListNode* r;
        ListNode* l_prev;
        ListNode* r_next;
        ListNode* cur = head;
        ListNode* prev;

        int pos = 1;
        if (left==right) return head;
        while (cur!=NULL){
            if (pos==left){
                l=cur;
                l_prev=prev;
            }
            else if (pos==right){
                r=cur;
                r_next=cur->next;
                r->next=NULL;
                break;
            }
            prev=cur;
            cur=cur->next;
            pos++;
        }
        l = reverse(l);
        cur = l;
        while (cur->next!=NULL){
            cur=cur->next;
        }
        if (l_prev!=NULL){
            l_prev->next=l;
        }
        if (r_next!=NULL){
            cur->next=r_next;
        }

        if (l_prev!=NULL){
            return head;
        }
        return r;
    }
};