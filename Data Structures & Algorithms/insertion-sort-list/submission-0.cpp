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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while (cur!=NULL){
            arr.push_back(cur->val);
            cur = cur->next;
        }
        sort(arr.begin(),arr.end());
        cur = head;
        int i=0;
        while (cur!=NULL){
            cur->val = arr[i];
            cur = cur->next;
            i++;
        }
        return head;
    }
};