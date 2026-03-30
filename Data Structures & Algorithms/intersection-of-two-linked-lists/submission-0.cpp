/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> s;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        while (cur1!=NULL){
            s.insert(cur1);
            cur1 = cur1->next;
        }
        while (cur2!=NULL){
            if (s.find(cur2)!=s.end()) return cur2;
            cur2 = cur2->next;
        }
        return NULL;
    }
};