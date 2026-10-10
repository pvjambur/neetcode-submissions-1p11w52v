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
class BSTIterator {
private:
    vector<int> vals;
    int i,n;

    void dfs(TreeNode* root){
        if (root->left) dfs(root->left);
        vals.push_back(root->val);
        if (root->right) dfs(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        dfs(root);
        i=-1;
        n=vals.size();
    }
    
    int next() {
        i++;
        if (i==n) return -1;
        return vals[i];
    }
    
    bool hasNext() {
        return !(i==n-1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */