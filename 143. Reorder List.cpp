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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *other = slow->next;
        slow->next = NULL;
        
        ListNode *p_pre = NULL;
        ListNode *p = other;
        ListNode *p_next = other->next;
        
        while (p_next) {
            ListNode *tmp = p_next->next;
            p_next->next = p;
            p->next = p_pre;
            p_pre = p;
            p = p_next;
            p_next = tmp;
        }
        
        ListNode *q = p;
        p = head;
        while (q) {
            ListNode *tmp_p = p->next;
            ListNode *tmp_q = q->next;
            q->next = NULL;
            p->next = q;
            q->next = tmp_p;
            q = tmp_q;
            p = tmp_p;
        }
        
    }
};