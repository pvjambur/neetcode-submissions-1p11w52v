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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = new TreeNode(-1);
        bool flag = false;
        while (!q.empty()){
            
            int sz = q.size();
            for (int i=0;i<sz;i++){
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left){
                    if (flag) return false;
                    q.push(temp->left);
                }
                else{
                    flag = true;
                }

                if (temp->right){
                    if (flag) return false;
                    q.push(temp->right);
                }
                else{
                    flag = true;
                }
            }
        }

        return true;
    }
};