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
vector<int> nums;

private:
    void dfs(TreeNode* node, int num){
        if (!node) return;
        bool t1 = !(node->left);
        bool t2 = !(node->right);
        int temp = 10*num + (node->val);

        if (t1 && t2){
            nums.push_back(temp);
            return;
        }
        else if (t1){
            dfs(node->right,temp);
        }
        else if (t2){
            dfs(node->left,temp);
        }
        else{
            dfs(node->left,temp);
            dfs(node->right,temp);
        }

    }

public:
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        int res =0;
        for (int x: nums){
            res += x;
        }
        return res;

    }
};