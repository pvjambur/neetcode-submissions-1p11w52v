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
    bool isPalindrome(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* s = head;
        ListNode* f = head;
        int size=0;
        int ind=0;
        ListNode* cur = head;
        while (cur!=NULL){
            size++;
            cur = cur->next;
        }
        if (size%2==0){
            while (f!=NULL){
                mp[ind] = s->val;
                if (f->next->next==NULL){
                    s = s->next;
                    break;
                }
                s = s->next;
                f = f->next->next;
                ind++;
            }
        }
        else{
            while (f!=NULL){
                mp[ind] = s->val;
                if (f->next==NULL){
                    break;
                }
                s = s->next;
                f = f->next->next;
                ind++;
            }
        }
        while (s!=NULL){
            if (mp[ind] == s->val){
                mp.erase(ind);
                ind--;
                s = s->next;
            }
            else return false;
        }
        return true;
    }
};