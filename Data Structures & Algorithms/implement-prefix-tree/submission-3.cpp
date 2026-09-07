class PrefixTree {
private:
    struct Trie{
        vector<Trie*> child;
        bool isEnd;

        Trie():  child(26,nullptr), isEnd(false) {}
    };

public:
    Trie* root = new Trie();
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Trie* node = root;
        for (char c: word){
            int idx = (int)(c-'a');
            if (!node->child[idx]){
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
        }
        node-> isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = root;
          for (char c: word){
            int idx = (int)(c-'a');
            if (!node->child[idx]) return false;

            node = node->child[idx];
          }
          return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = root;
        for (char c: prefix){
            int idx = (int)(c-'a');
            if (!node->child[idx]) return false;

            node =node->child[idx];
        }
        return true;
    }
};
