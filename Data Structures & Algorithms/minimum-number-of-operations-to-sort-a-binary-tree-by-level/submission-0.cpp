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
        int minimumOperations(TreeNode* root) {
            int answer = 0;
            vector<TreeNode*> nodes{root};
            while (!nodes.empty()) {
                vector<pair<int, int>> order;
                vector<TreeNode*> next;
                for (int i = 0; i < nodes.size(); i++) {
                    auto node = nodes[i];
                    order.push_back({node->val, i});
                    if (node->left) next.push_back(node->left);
                    if (node->right) next.push_back(node->right);
                }
                sort(order.begin(), order.end());
                vector<bool> seen(order.size());
                for (int i = 0; i < order.size(); i++) {
                    int length = 0, j = i;
                    while (!seen[j]) {
                        seen[j] = true;
                        length++;
                        j = order[j].second;
                    }
                    answer += max(0, length - 1);
                }
                nodes = move(next);
            }
            return answer;
        }
};
