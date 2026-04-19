/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int robbing(TreeNode* root, int skip){
        if (!root) return 0;
        if (skip==1){
            return robbing(root->left,0) + robbing(root->right,0);
        }
        return max(root->val + robbing(root->left,1) + robbing(root->right,1),robbing(root->left,0) + robbing(root->right,0));
    }

public:
    int rob(TreeNode* root) {
        int money = max(robbing(root,0),robbing(root,1));
        return money;
    }
};