/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* preHead = new ListNode(0);
        preHead->next = head;

        ListNode* pre = preHead;
        ListNode* tail = pre;
        while (pre->next) {
            int i = k;
            while (i-- > 0) {
                if (!tail->next) return preHead->next;
                tail = tail->next;
            }
            pre = reverse(pre, tail);
            tail = pre;
        }
        return preHead->next;
    }

    ListNode* reverse(ListNode* pre, ListNode* tail) {
        ListNode* nxt = pre->next;
        ListNode* tailNext = tail->next;
        while (pre->next && pre->next != tail) {
            ListNode* p = pre->next;
            pre->next = p->next;
            p->next = tailNext;
            tail->next = p;
            tailNext = p;
        }
        return nxt;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1 || head == NULL) return head;
        ListNode *p = head;
        vector<ListNode *> heads;
        vector<ListNode *> ends;
        ListNode *rest = NULL;
        int step = 0;
        while (p) {
            if (step == 0) {
                heads.push_back(p);
            }
            if (step == k - 1) {
                ends.push_back(p);
                step = 0;
            } else {
                if (p->next == NULL) {
                    if (ends.empty()) return head;
                    rest = heads.back();
                    heads.pop_back();
                    break;
                }
                step++;
            }
            p = p->next;
        }
        
        for (int i = 0; i < ends.size(); i++) {
            ends[i]->next = NULL;
        }
        
        for (int i = 0; i < heads.size(); i++) {
            ListNode *p_pre = NULL;
            ListNode *p_next = NULL;
            p = heads[i];
            while (p) {
                p_next = p->next;
                p->next = p_pre;
                
                p_pre = p;
                p = p_next;
            }
        }
        
        for (int i = 0; i < heads.size() - 1; i++) {
            heads[i]->next = ends[i+1];
        }
        
        if (!heads.empty()) heads.back()->next = rest;
        
        return ends[0];
        
    }
};
**/
