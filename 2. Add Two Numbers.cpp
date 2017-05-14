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
        ListNode *p1, *p2, *p3, *head;
        head = p3 = new ListNode(0);
        p1 = l1;
        p2 = l2;
        int carry = 0;
        while (p1 || p2 || carry) {
            int num = (p1?p1->val:0) + (p2?p2->val:0) + carry;
            carry = num / 10;
            ListNode* p = new ListNode(num % 10);
            p3->next = p;
            p1 = p1?p1->next:p1;
            p2 = p2?p2->next:p2;
            p3 = p3->next;
        }
        return head->next;
    }
};