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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *slow, *fast;
        slow = fast = head;
        bool has_cycle = false;
        while (slow && fast) {
            slow = slow->next;
            if (fast->next) fast = fast->next->next;
            else return NULL;
            if (slow == fast) {
                has_cycle = true;
                break;
            }
        }
        if (!has_cycle) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};