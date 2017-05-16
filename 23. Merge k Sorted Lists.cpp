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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> ps;
        for (size_t i = 0; i < lists.size(); i++) {
            ps.push_back(lists[i]);
        }
        ListNode *p = new ListNode(INT_MIN);
        ListNode *head = NULL;
        while (1) {
            size_t min = -1;
            for (size_t i = 0; i < ps.size(); i++) {
                if ((min == -1 && ps[i]) || (ps[i] && (ps[i]->val < ps[min]->val))) {
                    min = i;
                }
            }
            if (min == -1) break;
            p = p->next = ps[min];
            ps[min] = ps[min]->next;
            if (!head) head = p;
        }
        return head;
    }
};