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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *start, *end;
        ListNode *start_prev, *end_next;
        ListNode *p = head;
        ListNode *pre_node = new ListNode(0);
        pre_node->next = head;
        ListNode *p_prev = pre_node;
        size_t i = 0;
        m = m - 1;
        n = n - 1;
        start_prev = pre_node;
        end_next = NULL;
        while (i <= n) {
            if (i == m) {
                start_prev = p_prev;
                start = p;
                p = p->next;
                p_prev = p_prev->next;
            } else if (i > m && i <= n) {
                if (i == n) {
                    end = p;
                    end_next = p->next;
                }
                ListNode *tmp = p->next;
                p->next = p_prev;
                p_prev = p;
                p = tmp;
            } else {
                p = p->next;
                p_prev = p_prev->next;
            }
            i++;
        }
        start_prev->next = end;
        start->next = end_next;
        return pre_node->next;
    }
};