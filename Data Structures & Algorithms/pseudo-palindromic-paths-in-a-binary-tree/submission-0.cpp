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
    int pseudoPalindromicPaths(TreeNode* root) {
int answer=0;vector<pair<TreeNode*,int>> stack{{root,0}};while(!stack.empty()){auto [node,mask]=stack.back();stack.pop_back();mask^=1<<node->val;if(!node->left&&!node->right&&(mask&(mask-1))==0)answer++;if(node->left)stack.push_back({node->left,mask});if(node->right)stack.push_back({node->right,mask});}return answer;
}
};
