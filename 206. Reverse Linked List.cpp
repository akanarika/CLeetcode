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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        
        if (head->next != NULL) {
            ListNode* node = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return node;
        } else {
            return head;
        }
    }
};

/**

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* p_next = head->next;
        while (p_next) {
            ListNode* tmp = p_next->next;
            p_next->next = p;
            if (p == head) p->next = NULL;
            p = p_next;
            p_next = tmp;
        }
        return p;
    }
};
**/