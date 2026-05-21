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
    void insert(TreeNode* node, int val){
        if (!node) return;
        bool L = (val < node->val);
        bool R = (node->val < val);

        if (L){
            if (node->left) insert(node->left,val);
            else{
                TreeNode* res = new TreeNode(val);
                node->left = res;
                return;
            }
        }
        if (R){
            if (node->right) insert(node->right,val);
            else{
                TreeNode* res = new TreeNode(val);
                node->right = res;
                return;
            }
        }
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root){
            TreeNode* res = new TreeNode(val);
            return res;
        }
        insert(root,val);
        return root;
    }
};