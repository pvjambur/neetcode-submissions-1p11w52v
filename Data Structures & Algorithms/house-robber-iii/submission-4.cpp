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
    unordered_map<TreeNode*,vector<int>> dp;
    int dfs(TreeNode* node, int pick){
        if (!node) return 0;
        if (dp.count(node) && dp[node][pick]!=-1) return dp[node][pick];
        int res = 0;
        if (pick){
            int val = node->val;
            res = max(val + dfs(node->left,0) + dfs(node->right,0),dfs(node->left,1) + dfs(node->right,1));
        }
        else{
            res = dfs(node->left,1) + dfs(node->right,1);
        }
        if (dp.count(node)){
            return dp[node][pick] = res;
        }
        dp[node] = {-1,-1};
        return dp[node][pick] = res;
    }

public:
    int rob(TreeNode* root) {
        return max(dfs(root,0),dfs(root,1));
    }
};