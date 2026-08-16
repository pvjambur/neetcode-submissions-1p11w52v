class WordDictionary {
private:
    struct Trie{
        vector<Trie*> child;
        bool isEnd;
        Trie(): child(26,nullptr),isEnd(false) {}
    };

    Trie* root = new Trie();

    bool dfs(int ind, string& word, Trie* node){
        Trie* cur = node;
        int n = word.size();
        for (int i=ind;i<n;i++){
            if (word[i]=='.'){
            
                for (int j=0;j<26;j++){
                    if (!cur->child[j]) continue;
                    if (dfs(i+1,word,cur->child[j])) return true;
                }
                return false;
            }
            int idx = (int)(word[i]-'a');
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie* cur = root;
        for (char c: word){
            int idx = (int)(c-'a');
            if (!cur->child[idx]){
                cur->child[idx] = new Trie();
            }
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(0,word,root);
    }
};
