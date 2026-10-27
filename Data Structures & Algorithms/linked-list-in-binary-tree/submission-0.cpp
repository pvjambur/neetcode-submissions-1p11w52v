
class Solution {
    bool check(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root || head->val != root->val) return false;

        return check(head->next, root->left) ||
               check(head->next, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        return check(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};
