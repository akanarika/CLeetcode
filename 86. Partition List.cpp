/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* other = new ListNode(0);
        ListNode* p_prev = first;
        ListNode* p = head;
        ListNode* q = other;
        while (p) {
            if (p->val >= x) {
                p_prev->next = p->next;
                q->next = p;
                p->next = NULL;
                q = p;
                p = p_prev->next;
            } else {
                p = p->next;
                p_prev = p_prev->next;
            }
        }
        p_prev->next = other->next;
        return first->next;
    }
};