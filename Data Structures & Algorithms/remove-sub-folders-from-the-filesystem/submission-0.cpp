class Solution {

    struct TrieNode {

        unordered_map<string, TrieNode*> child;
        bool isEnd = false;
    };

    TrieNode* root = new TrieNode();

public:

    bool insert(string path) {

        TrieNode* node = root;

        stringstream ss(path);
        string part;

        vector<string> folders;

        while (getline(ss, part, '/')) {

            if (!part.empty()) {
                folders.push_back(part);
            }
        }

        // Check if parent exists
        for (string& f : folders) {

            if (!node->child.count(f)) {
                break;
            }

            node = node->child[f];

            if (node->isEnd) {
                return false;
            }
        }

        // Insert
        node = root;

        for (string& f : folders) {

            if (!node->child.count(f)) {
                node->child[f] = new TrieNode();
            }

            node = node->child[f];
        }

        node->isEnd = true;

        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());

        vector<string> res;

        for (string& f : folder) {

            if (insert(f)) {
                res.push_back(f);
            }
        }

        return res;
    }
};