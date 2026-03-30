class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* dummy = new Node(0);
        Node* new_cur = dummy;
        Node* cur = head;

        unordered_map<Node*, Node*> mp;

        while (cur != NULL) {
            Node* temp = new Node(cur->val);
            new_cur->next = temp;
            new_cur = temp;
            mp[cur] = temp; 
            cur = cur->next;
        }

        cur = head;
        new_cur = dummy->next;

        while (cur != NULL) {
            if (cur->random == NULL)
                new_cur->random = NULL;
            else
                new_cur->random = mp[cur->random];

            cur = cur->next;
            new_cur = new_cur->next;
        }

        return dummy->next;
    }
};