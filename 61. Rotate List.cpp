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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        ListNode *p = head;
        int n = 1;
        while (p->next) {
            p = p->next;
            n++;
        }
        ListNode *end = p;
        end->next = head;
        k = k % n;
        ListNode *new_head = head;
        ListNode *prev = end;
        int step = n - k;
        while (step) {
            new_head = new_head->next;
            prev = prev->next;
            step--;
        }
        prev->next = NULL;
        return new_head;
    }
};