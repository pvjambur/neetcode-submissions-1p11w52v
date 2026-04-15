class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Case 2: path passing through this node
        maxSum = max(maxSum, left + right + root->val);

        // Case 1: return best single path upward
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};