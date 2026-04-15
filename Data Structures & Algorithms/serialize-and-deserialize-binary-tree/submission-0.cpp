class Codec {
public:

    // Serialize
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        return res;
    }

    void dfsSerialize(TreeNode* root, string &res) {
        if (!root) {
            res += "N,";
            return;
        }
        res += to_string(root->val) + ",";
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int i = 0;
        return dfsDeserialize(nodes, i);
    }

    TreeNode* dfsDeserialize(vector<string>& nodes, int &i) {
        if (nodes[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root->left = dfsDeserialize(nodes, i);
        root->right = dfsDeserialize(nodes, i);

        return root;
    }
};