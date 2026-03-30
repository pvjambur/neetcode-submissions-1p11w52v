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
    void dfs(TreeNode* node, vector<int>& bst){
        if (!node) return;
        if (node->left) dfs(node->left,bst);
        bst.push_back(node->val);
        if (node->right) dfs(node->right,bst);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> bst;
        dfs(root,bst);
        int n = bst.size();
        return bst[k-1];
    }
};
