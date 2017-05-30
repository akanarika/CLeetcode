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
    ListNode* plusOne(ListNode* head) {
        ListNode *pre_node = new ListNode(0);
        ListNode *tail;
        ListNode *p_prev = pre_node;
        ListNode *p = head;
        ListNode *tmp;
        
        while (p) {
            tmp = p->next;
            p->next = p_prev;
            p_prev = p;
            p = tmp;
        }
        
        tail = p_prev;
        p = tail;
        
        int carry = 0;
        int num = 1;
        while (p) {
            num += p->val + carry;
            carry = num > 9 ? 1 : 0;
            p->val = num % 10;
            num = 0;
            p = p->next;
        }
        
        p_prev = tail;
        p = tail->next;
        tail->next = NULL;
        
        while (p) {
            tmp = p->next;
            p->next = p_prev;
            p_prev = p;
            p = tmp;
        }
        
        return pre_node->val ? pre_node : pre_node->next;
        
    }
};