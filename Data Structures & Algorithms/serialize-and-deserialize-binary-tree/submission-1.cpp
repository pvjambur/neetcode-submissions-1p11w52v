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

class Codec {
public:

    void dfs(TreeNode* node, string& s){
        if (!node){
            s += "N,";
            return;
        }
        string val = to_string(node->val) + ',';
        s += val;
        dfs(node->left,s);
        dfs(node->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root) return s;
        dfs(root,s);
        return s;
    }

    TreeNode* build(string& data, int& i){
        if (data[i]=='N'){
            i+=2;
            return nullptr;
        }

        int sign=1;
        if (data[i]=='-'){
            sign=-1;
            i++;
        }
        int val = 0;
        while (i<data.size() && data[i]!=','){
            val = 10*val + (int)(data[i]-'0');
            i++;
        }
        i++;
        TreeNode* root = new TreeNode(sign*val);
        root->left = build(data,i);
        root->right = build(data,i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="") return NULL;
        int i=0;
        return build(data,i);
    }
};
