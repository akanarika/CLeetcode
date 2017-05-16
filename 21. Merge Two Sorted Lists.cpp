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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode *p, *head;
        p = new ListNode(0);
        head = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 || p2) {
            if (!p1 || p2 && (p1->val > p2->val)) {
                p = p->next = p2;
                p2 = p2->next;
            } else if (!p2 || p1 && (p1->val) <= (p2->val)){
                p = p->next = p1;
                p1 = p1->next;
            }
            if (!head) head = p;
        }
        return head;
    }
};