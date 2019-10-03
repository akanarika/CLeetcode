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
        ListNode* pre = new ListNode(0);
        ListNode* p = pre;
        
        while (l1 || l2) {
            if ((l1 && !l2) || (l1 && l2 && l1->val <= l2->val)) {
                p->next = l1;
                l1 = l1->next;
            } else if ((l2 && !l1) || (l1 && l2 && l2->val < l1->val)) {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return pre->next;
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


