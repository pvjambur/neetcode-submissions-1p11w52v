class LFUCache {
private:
    struct Node{
        int key;
        int val;
        int f;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key = k;
            val = v;
            f = 1;
            next = prev = nullptr;
        }
    };

    struct DLL{
        Node* head;
        Node* tail;

        DLL(){
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
        }
        
        void add(Node* node){
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
        }

        void remove(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void removeLast(){
            Node* node = tail->prev;
            remove(node);
            delete node;
        }
    };

    unordered_map<int,Node*> mp;
    unordered_map<int,DLL*> freq;
    int cap;
    int minFreq = 1;

    

public:
    LFUCache(int capacity) {
        
        cap = capacity;
    }
    
    int get(int key) {
        if (cap==0) return -1;
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        int num = node->f;
        node->f++;
        freq[num]->remove(node);
        if (freq[num]->head->next==freq[num]->tail){
            if (minFreq==num) minFreq++;
            delete freq[num];
            freq.erase(num);
        }
        num++;
        if (!freq.count(num)){
            freq[num] = new DLL();
        }
        freq[num]->add(node);
        return node->val;

    }
    
    void put(int key, int value) {
        if (cap==0) return;
        if (!mp.count(key)){
            if (mp.size()==cap){
                int k = freq[minFreq]->tail->prev->key;
                mp.erase(k);
                freq[minFreq]->removeLast();
                if (freq[minFreq]->head->next==freq[minFreq]->tail){
                    delete freq[minFreq];
                    freq.erase(minFreq);
                }
            }
            minFreq = 1;
            Node* node = new Node(key,value);
            if (!freq.count(1)){
                freq[1] = new DLL();
            }
            freq[1]->add(node);
            mp[key] = node;
            return;
        }
        Node* node = mp[key];
        node->val = value;
        int num = node->f;
        node->f++;
        freq[num]->remove(node);
        if (freq[num]->head->next==freq[num]->tail){
            if (minFreq==num) minFreq++;
            freq.erase(num);
        }
        num++;
        if (!freq.count(num)){
            freq[num] = new DLL();
        }
        freq[num]->add(node);
       
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */