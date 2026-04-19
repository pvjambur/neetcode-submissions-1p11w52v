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
    int robbing(TreeNode* root, int skip, int level, unordered_map<int,int>& mp){
        if (!root) return 0;
        if (skip==1){
            if (mp.find(level)!=mp.end()) return mp[level];
            else mp[level] = robbing(root->left,0,level+1,mp) + robbing(root->right,0,level+1,mp);
            return mp[level];
        }
        if (mp.find(level)!=mp.end()) return mp[level];
        else mp[level] = max(root->val + robbing(root->left,1,level+1,mp) + robbing(root->right,1,level+1,mp),robbing(root->left,0,level+1,mp) + robbing(root->right,0,level+1,mp));
        return mp[level];
    }

public:
    int rob(TreeNode* root) {
        unordered_map<int,int> mp;
        int money = max(robbing(root,0,0,mp),robbing(root,1,0,mp));
        
        return money/2;
    }
};