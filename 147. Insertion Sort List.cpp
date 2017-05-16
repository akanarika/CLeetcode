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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre_node = new ListNode(0);
        pre_node->next = head;
        ListNode *prev = pre_node;
        ListNode *curr = head;
        while (curr) {
            if (curr->next && curr->next->val < curr->val) {
                while (prev->next && prev->next->val < curr->next->val) {
                    prev = prev->next;
                }
                ListNode *tmp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = tmp;
                prev = pre_node;
            } else {
                curr = curr->next;
            }
        }
        return pre_node->next;
    }
};