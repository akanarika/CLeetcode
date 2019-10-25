/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
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
        if (!head) return true;
        return isPalindrome(head, head);
    }

    bool isPalindrome(ListNode*& p, ListNode* q) {
        if (!q) return true;
        bool isP = isPalindrome(p, q->next);
        if (p->val == q->val) {
            p = p->next;
            return isP;
        }
        return false;
    }
};
// @lc code=end

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
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
**/
