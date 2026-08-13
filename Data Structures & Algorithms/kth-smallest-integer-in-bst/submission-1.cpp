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
    void dfs(TreeNode* node, priority_queue<int>& pq, int k){
        if (!node) return;
        pq.push(node->val);
        if (pq.size()>k) pq.pop();
        if (node->left) dfs(node->left,pq,k);
        if (node->right) dfs(node->right,pq,k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        dfs(root,pq,k);
        return pq.top();
    }
};
