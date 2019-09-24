/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> m;
        Node* newHead = new Node(head->val, NULL, NULL);
        Node* np = newHead;
        Node* p = head;
        while (p) {
            m[p] = np;
            if (p->next) {
                np->next = new Node(p->next->val, NULL, NULL);
            }
            p = p->next;
            np = np->next;
        }
        np = newHead;
        p = head;
        while (p) {
            if (p->random) {
                np->random = m[p->random];
            }
            p = p->next;
            np = np->next;
        }
        return newHead;
    }
};
