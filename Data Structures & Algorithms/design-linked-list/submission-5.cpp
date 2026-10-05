class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node* prev;

        Node (int v){
            val = v;
            next = prev = nullptr;
        }
    };

    Node* search(Node* head, Node* tail, bool flag, int index){
        Node* cur;
        if (flag){
            cur = head;
            int i=-1;
            while (i!=index){
                cur = cur->next;
                i++;
            }
        }
        else{
            cur = tail;
            int i=len;
            while (i!=index){
                cur = cur->prev;
                i--;
            }
        }
        return cur;
    }

    Node* head;
    Node* tail;
    int len;

public:
    MyLinkedList() {
        head = tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        len=0;
    }

    int get(int index) {
        Node* cur;
        if (index<0 || index>=len) return -1;
        int tres = len/2;
        bool flag;
        if (index<=tres){
            flag = true;
            cur = search(head,tail,flag,index);

        }
        else{
            flag = false;
            cur = search(head,tail,flag,index);
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        len++;
        Node* temp = new Node(val);
        Node* cur = head->next;
        cur->prev = temp;
        head->next = temp;
        temp->next = cur;
        temp->prev = head;
    }
    
    void addAtTail(int val) {
        len++;
        Node* temp = new Node(val);
        Node* cur = tail->prev;
        cur->next = temp;
        tail->prev = temp;
        temp->next = tail;
        temp->prev = cur;
    }
    
    void addAtIndex(int index, int val) {
        Node* cur;
        if (index<0 || index>len) return;
        int tres = len/2;
        bool flag;
        if (index<=tres){
            flag = true;
            cur = search(head,tail,flag,index);

        }
        else{
            flag = false;
            cur = search(head,tail,flag,index);
            
        }
        Node* temp = new Node(val);
        Node* tar = cur->prev;
        tar->next = temp;
        cur->prev = temp;
        temp->prev = tar;
        temp->next = cur;
        len++;
    }
    
    void deleteAtIndex(int index) {
        Node* cur;
        if (index<0 || index>=len) return;
        int tres = len/2;
        bool flag;
        if (index<=tres){
            flag = true;
            cur = search(head,tail,flag,index);

        }
        else{
            flag = false;
            cur = search(head,tail,flag,index);
            
        }
        Node* temp = cur->next;
        Node* tar = cur->prev;
        tar->next = temp;
        temp->prev = tar;
        cur->next = cur->prev = nullptr;
        delete cur;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */