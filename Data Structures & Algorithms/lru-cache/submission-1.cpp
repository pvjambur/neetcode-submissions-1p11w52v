class LRUCache {
private:
    struct Node{
        int key,val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k),val(v),prev(NULL),next(NULL) {}
    };

    int cap;

    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;

    void addNode(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
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
        if (mp.count(key)==0) return -1;
        Node* node = mp[key];
        removeNode(node);
        addNode(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        if (mp.count(key)!=0){
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNode(node);
        }
        else{
            if (mp.size()==cap){
                Node* node = tail->prev;
                removeNode(node);
                mp.erase(node->key);
                delete node;
                node = nullptr;
            }
            Node* temp = new Node(key,value);
            mp[key] = temp;
            addNode(temp);
        }
    }
};
