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
        ListNode* prev = NULL;
        ListNode* cur = node;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* cur = head;
        ListNode* temp_head = head;
        vector<ListNode*> arr;
        int len = 0;
        while (cur){
            prev = cur;
            cur = cur->next;
            len++;
            if (len%k==0){
                prev->next = NULL;
                arr.push_back(reverse(temp_head));
                temp_head = cur;
                prev = dummy;
                len = 0;
            }
        }
        if (temp_head!=NULL){
            arr.push_back(temp_head);
        }
        ListNode* res = new ListNode(0);
        cur = res;
        for (auto &ll: arr){
            cur->next = ll;
            ListNode* temp = ll;
            while (temp->next){
                temp = temp->next;
            }
            cur = temp;
        }
        cur->next = NULL;
        return res->next;
    }
};
