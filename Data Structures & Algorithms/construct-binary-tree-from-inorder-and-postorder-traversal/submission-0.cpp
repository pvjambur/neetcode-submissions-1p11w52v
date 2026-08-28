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
    int postfix;
    TreeNode* build(int l, int r, vector<int>& inorder, vector<int>& postorder){
        if (l>r || postfix<0) return nullptr;
        postfix--;
        int ind = 0;
        for (int i=l;i<=r;i++){
            if (inorder[i]==postorder[postfix]){
                ind = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[ind]);
        root->right = build(ind+1,r,inorder,postorder);
        root->left = build(l,ind-1,inorder,postorder);
        return root;
        

    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postfix=n;
        return build(0,n-1,inorder,postorder);
    }
};