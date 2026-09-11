class Solution {
private:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);

        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            second = root;
        }

        prev = root;

        dfs(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};