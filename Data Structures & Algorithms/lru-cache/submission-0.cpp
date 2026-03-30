class LRUCache {
private:
    struct Node{
        int key,val;
        Node* prev;
        Node* next;
        Node(int k,int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;

    void addNode(Node* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);
        addNode(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNode(node);
        }
        else{
            if (mp.size()==cap){
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
                lru = nullptr;
            }
            Node* newNode = new Node(key,value);
            mp[key] = newNode;
            addNode(newNode);

        }
    }
};
