class Solution {
private:
    int maxDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = maxDepth(node->left);
        int right = maxDepth(node->right);

        return std::max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftD = maxDepth(root->left);
        int rightD = maxDepth(root->right);
        int currD = leftD + rightD;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return std::max(currD, std::max(leftDiameter, rightDiameter));
    }
};
