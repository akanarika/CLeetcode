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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return 1;
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        vector<int> stack;
        while (fast && fast->next) {
            stack.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        while (!stack.empty()) {
            if (slow->val != stack.back()) return 0;
            stack.pop_back();
            slow = slow->next;
        }
        return 1;
    }
};