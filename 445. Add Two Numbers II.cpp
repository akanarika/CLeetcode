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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int n1, n2;
        n1 = n2 = 0;
        while (p1 || p2) {
            if (p1) {
                p1 = p1->next;
                n1++;
            }
            if (p2) {
                p2 = p2->next;
                n2++;
            }
        }
        ListNode *pre_node = new ListNode(0);
        ListNode *p = pre_node;
        p1 = l1;
        p2 = l2;
        while (n1 || n2) {
            if (n1 > n2) {
                ListNode *tmp = new ListNode(p1->val);
                p->next = tmp;
                p1 = p1->next;
                n1--;
            } else if (n2 > n1) {
                ListNode *tmp = new ListNode(p2->val);
                p->next = tmp;
                p2 = p2->next;
                n2--;
            } else {
                ListNode *tmp = new ListNode(p1->val + p2->val);
                p->next = tmp;
                p1 = p1->next;
                p2 = p2->next;
                n1--;
                n2--;
            }
            p = p->next;
        }
        
        bool clean = false;
        while (!clean) {
            clean = true;
            p1 = pre_node;
            p2 = pre_node->next;
            while (p2) {
                if (p2->val >= 10) {
                    p1->val++;
                    if (p1->val >= 10) clean = false;
                    p2->val -= 10;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return pre_node->val ? pre_node : pre_node->next;

    }
};