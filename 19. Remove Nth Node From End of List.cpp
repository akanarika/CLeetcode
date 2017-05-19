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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre_node = new ListNode(0);
        pre_node->next = head;
        ListNode *pre, *p, *end;
        pre = pre_node;
        end = head;
        for (size_t i = 0; i < n; i++) {
            end = end->next;
        }
        p = head;
        while (end) {
            pre = pre->next;
            p = p->next;
            end = end->next;
        }
        pre->next = p->next;
        head = pre_node->next;
        return head;
    }
};