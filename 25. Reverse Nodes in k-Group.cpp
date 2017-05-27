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