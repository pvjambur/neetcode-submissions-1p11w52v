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
public:
    vector<int> arr;
    int val;
    void search(TreeNode* node){
        if (!node) return;
        if (arr.size()>=val) return;
        if (node->left) search(node->left);
        if (arr.size()>=val) return;
        arr.push_back(node->val);
        if (arr.size()>=val) return;
        if (node->right) search(node->right);
        if (arr.size()>=val) return;
    }

    int kthSmallest(TreeNode* root, int k) {
        val = k;
        search(root);
        return arr[k-1];
    }
};
