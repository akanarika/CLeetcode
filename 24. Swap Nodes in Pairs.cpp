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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre_node = new ListNode(0);
        ListNode* p_prev = pre_node;
        ListNode* p = head;
        ListNode* p_next;
        while (p && p->next) {
            p_next = p->next;
            p->next = p_next->next;
            p_next->next = p;
            p_prev->next = p_next;
            p_prev = p;
            p = p->next;
        }
        return pre_node->next;
    }
};