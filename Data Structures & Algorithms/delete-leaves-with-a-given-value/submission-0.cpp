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
    bool delete1(TreeNode* root, int target){
        if (!root) return true;
        bool l = delete1(root->left,target);
        bool r = delete1(root->right,target);

        if (l) root->left = NULL;
        if (r) root->right = NULL;
        if (l && r && root->val==target) return true;
        return false;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool flag = delete1(root,target);
        if (root!=NULL && root->val==target && root->left==NULL && root->right==NULL) root=NULL;
        return root;
    }
};