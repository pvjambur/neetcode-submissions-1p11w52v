class WordDictionary {
public:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            isEnd = false;
            for (int i=0;i<26;i++) children[i] = nullptr;
        }
    };

    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c: word){
            int idx = c - 'a';
            if (!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }

    bool dfs(string& word, int i, TrieNode* node){
        if (!node) return false;

        if (i==word.size()){
            return node->isEnd;
        }

        char c = word[i];

        if (c == '.'){
            for (int j=0;j<26;j++){
                if (node->children[j] && dfs(word,i+1,node->children[j])){
                    return true;
                }
            }
            return false;
        }
        else{
            return dfs(word,i+1,node->children[c-'a']);
        }
    }
};
