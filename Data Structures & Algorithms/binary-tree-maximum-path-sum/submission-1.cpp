class Solution {
public: 
    int maxSum = INT_MIN;

    int dfs(TreeNode* node){
        if (!node) return 0;

        int left = max(0,dfs(node->left));
        int right = max(0,dfs(node->right));

        maxSum = max(maxSum,left + right + node->val);

        return node->val + max(left,right);
    }
   
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
        
    }
};