class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
        word = "";
    }
};

class Solution {
public:
    vector<string> res;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#' || node->children[ch - 'a'] == NULL)
            return;

        node = node->children[ch - 'a'];

        if (node->word != "") {
            res.push_back(node->word);
            node->word = ""; 
        }

        board[r][c] = '#';

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size())
                dfs(board, nr, nc, node);
        }

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode* root = new TrieNode();

        for (string word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c-'a'])
                    node->children[c-'a'] = new TrieNode();
                node = node->children[c-'a'];
            }
            node->word = word;
        }

        int m = board.size();
        int n = board[0].size();

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                dfs(board,i,j,root);
            }
        }

        return res;
    }
};