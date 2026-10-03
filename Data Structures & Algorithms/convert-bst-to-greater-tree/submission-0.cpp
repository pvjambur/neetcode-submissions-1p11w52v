class Solution {
private:
    void dfs(TreeNode* root, int& val) {
        if (!root) return;

        dfs(root->right, val);

        val += root->val;
        root->val = val;

        dfs(root->left, val);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        dfs(root, val);
        return root;
    }
};