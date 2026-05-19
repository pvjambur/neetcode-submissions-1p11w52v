/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    TreeNode* LCA = new TreeNode(0);

    bool findLCA(TreeNode* node, TreeNode* p, TreeNode* q){
        if (!node) return false;

        bool findN = (node->val==p->val || node->val==q->val);
        bool findL = findLCA(node->left,p,q);
        bool findR = findLCA(node->right,p,q);

        if ((findN && findL) || (findN && findR) || (findL && findR)){
            LCA = node;
        }

        return findN || findL || findR;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool res = findLCA(root,p,q);
        if (!res) return NULL;
        return LCA;
    }
};