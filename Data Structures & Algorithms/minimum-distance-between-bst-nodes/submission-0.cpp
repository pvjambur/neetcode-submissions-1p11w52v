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
    int diff = INT_MAX;
    int cur = -1;

    void dfs(TreeNode* node){
        if (node->left) dfs(node->left);
        if (cur!=-1) {
            diff = min(diff,node->val - cur);
        }
        cur = node->val;
        if (node->right) dfs(node->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return diff;
    }
};
