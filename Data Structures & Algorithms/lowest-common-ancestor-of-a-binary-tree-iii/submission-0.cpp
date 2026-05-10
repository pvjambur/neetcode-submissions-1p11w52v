/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> st;

        while (p!=NULL){
            st.insert(p);
            p = p->parent;
        }

        while (q!=NULL){
            if (st.count(q)) return q;
            q = q->parent;
        }

        return NULL;
    }
};