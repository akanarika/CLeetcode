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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* mid;
        ListNode* mid2;
        ListNode* end;
        mid = end = head;
        while (end && end->next && end->next->next) {
            mid = mid->next;
            end = end->next->next;
        }
        if (end && end->next) {
            end = end->next;
        }
        mid2 = mid->next;
        mid->next = NULL;
        return mergeList(sortList(head), sortList(mid2));
    }
    
    ListNode* mergeList(ListNode* head, ListNode* mid2) {
        ListNode* p1 = head;
        ListNode* p2 = mid2;
        ListNode* p;
        ListNode* new_head;
        p = new ListNode(0);
        new_head = NULL;
        while (p1 != NULL || p2 != NULL) {
            if (p1 == NULL) {
                p->next = p2;
                p2 = p2->next;
            } else if (p2 == NULL) {
                p->next = p1;
                p1 = p1->next;
            } else {
                if(p1->val > p2->val) {
                    p->next = p2;
                    p2 = p2->next;
                } else {
                    p->next = p1;
                    p1 = p1->next;
                }
            }
            p = p->next;
            if (new_head == NULL) new_head = p;
        }
        return new_head;
    }
};