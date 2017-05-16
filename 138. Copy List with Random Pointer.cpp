/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        std::unordered_map<RandomListNode *, RandomListNode *> dict;
        RandomListNode *new_head = NULL;
        RandomListNode *p = head;
        RandomListNode *q = new RandomListNode(0);
        while (p) {
            q = q->next = new RandomListNode(p->label);
            if (!new_head) new_head = q;
            dict[p] = q;
            p = p->next;
        }
        p = head;
        q = new_head;
        while (p) {
            q->random = p->random ? dict[p->random] : NULL;
            p = p->next;
            q = q->next;
        }
        return new_head;
    }
};