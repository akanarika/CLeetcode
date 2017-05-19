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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        int curr = head->val;
        ListNode *p_prev, *p;
        p_prev = head;
        p = head->next;
        while (p) {
            if (p->val == curr) {
                p_prev->next = p->next;
                p = p->next;
            } else {
                curr = p->val;
                p = p->next;
                p_prev = p_prev->next;
            }
        }
        return head;
    }
};