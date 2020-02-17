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
        map<int, unordered_set<ListNode*>> m;
        for (auto node : lists) {
            if (!node) continue;
            m[node->val].insert(node);
        }
        
        ListNode* newHead = new ListNode(0);
        ListNode* p = newHead;
        while (!m.empty()) {
            ListNode* h = *(m.begin()->second).begin();
            ListNode* hn = h->next;
            m.begin()->second.erase(h);
            if (m.begin()->second.empty()) m.erase(m.begin()->first);
            h->next = NULL;
            p->next = h;
            p = p->next;
            if (hn) m[hn->val].insert(hn);
        }
        return newHead->next;
    }
};

/**
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

**/