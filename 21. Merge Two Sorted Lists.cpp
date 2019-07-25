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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode *p, *head;
        p = new ListNode(0);
        head = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 || p2) {
            if (!p1 || p2 && (p1->val > p2->val)) {
                p = p->next = p2;
                p2 = p2->next;
            } else if (!p2 || p1 && (p1->val) <= (p2->val)){
                p = p->next = p1;
                p1 = p1->next;
            }
            if (!head) head = p;
        }
        return head;
    }
};

/**
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode _pre(0);
        ListNode *pre = &_pre;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if (l1 || l2) {
            pre->next = l1 ? l1 : l2;
        }

        return _pre.next;
    }
};
**/