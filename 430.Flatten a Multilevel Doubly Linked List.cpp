/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        return flatten(head, NULL); 
    }

    Node* flatten(Node* head, Node* tail) {
        Node* pre = new Node(0, NULL, head, NULL);
        Node* p = pre;
        Node* q = head;
        while (q) {
            if (q->child) {
                cout << q->child->val << endl;
                Node* qn = q->next;
                Node* t;
                Node* f = flatten(q->child, t);
                q->child = NULL;
                f->prev = q;
                q->next = f;
                qn->prev = t;
                t->next = qn;
                q = qn;
                p = t;
            } else {
                q = q->next;
                p = p->next;
            }
        }
        tail = new Node(0, NULL, NULL, NULL);
        if (p) *tail = *p;
        else tail = NULL;
        return pre->next;
    }
};
