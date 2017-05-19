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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *pre_node = new ListNode(0);
        pre_node->next = head;
        ListNode *p_prev, *p;
        p_prev = pre_node;
        p = head;
        while (p) {
            if (p->val == val) {
                p_prev->next = p->next;
                p->next = NULL;
                p = p_prev->next;
            } else {
                p = p->next;
                p_prev = p_prev->next;
            }
        }
        return pre_node->next;
    }
};