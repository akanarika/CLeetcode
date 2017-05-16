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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *odd, *even, *even_head;
        odd = head;
        even_head = even = head->next;
        while ((odd && odd->next && odd->next->next)
               && (even && even->next && even->next->next)) {
            odd = odd->next = odd->next->next;
            even = even->next = even->next->next;
        }
        if (odd && odd->next && odd->next->next) {
            odd = odd->next = odd->next->next;
        }
        even->next = NULL;
        odd->next = even_head;
        return head;
    }
};