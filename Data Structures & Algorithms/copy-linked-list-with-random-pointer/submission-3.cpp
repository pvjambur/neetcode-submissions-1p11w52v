class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        // Create copy of every node
        Node* cur = head;

        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Connect next and random pointers
        cur = head;

        while (cur) {
            if (cur->next)
                mp[cur]->next = mp[cur->next];

            if (cur->random)
                mp[cur]->random = mp[cur->random];

            cur = cur->next;
        }

        return mp[head];
    }
};