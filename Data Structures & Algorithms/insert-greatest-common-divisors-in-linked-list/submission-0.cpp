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
    void insertNode(ListNode* node1, ListNode* node2, int num){
        ListNode* temp = new ListNode(num);
        node1->next = temp;
        temp->next = node2;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur->next!=NULL){
            ListNode* temp = cur->next;
            int num = gcd(cur->val,temp->val);
            insertNode(cur,temp,num);
            cur = temp;
        }
        return head;
    }
};