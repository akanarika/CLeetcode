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
        if (head == NULL || head->next == NULL) return head;
        ListNode *pre_node = new ListNode(0);
        pre_node->next = head;
        ListNode *prepre = pre_node;
        ListNode *pre = head;
        ListNode *p = head->next;
        bool is_dup = false;
        while (p) {
            if (p->val == pre->val) {
                is_dup = true;
                p = p->next;
                pre->next = p;
            } else {
                if (is_dup) {
                    prepre->next = p;
                    pre = p;
                    p = p->next;
                } else {
                    prepre = prepre->next;
                    pre = pre->next;
                    p = p->next;
                }
                is_dup = false;
            }
        }
        if (is_dup) {
            prepre->next = p;
        }
        
        return pre_node->next;
    }
};