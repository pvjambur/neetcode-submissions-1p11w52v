class LRUCache {
private:
    struct Node{
        int val,key;
        Node* next;
        Node* prev;
        Node (int k, int v){
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    Node* head,*tail;
    unordered_map<int,Node*> mp;
    int cap;

    Node* remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }

    void add(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
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
        if (mp.count(key)){
            Node* temp = remove(mp[key]);
            add(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)){
            Node* temp = remove(mp[key]);
            add(temp);
            temp->val = value;
            return;
        }

        if (mp.size()==cap){
            Node* temp = remove(tail->prev);
            mp.erase(temp->key);
            delete temp;
        }
        Node* node = new Node(key,value);
        mp[key] = node;
        add(node);
    }
};
