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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* p = head;
		ListNode* q = head;
		while (q->next && q->next->next) {
			p = p->next;
			q = q->next->next;
		}
		ListNode* mid = p->next;
		p->next = NULL;
		return merge(sortList(head), sortList(mid));
	}

	ListNode* merge(ListNode* l, ListNode* r) {
		ListNode* pre = new ListNode(0);
		ListNode* p = pre;
		while (l || r) {
			if (!l || (l && r && l->val > r->val)) {
				p->next = r;
				r = r->next;
			}
			else if (!r || (l && r && l->val <= r->val)) {
				p->next = l;
				l = l->next;
			}
			p = p->next;
		}
		return pre->next;
	}
};

/**
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* mid;
        ListNode* mid2;
        ListNode* end;
        mid = end = head;
        while (end && end->next && end->next->next) {
            mid = mid->next;
            end = end->next->next;
        }
        if (end && end->next) {
            end = end->next;
        }
        mid2 = mid->next;
        mid->next = NULL;
        return mergeList(sortList(head), sortList(mid2));
    }
    
    ListNode* mergeList(ListNode* head, ListNode* mid2) {
        ListNode* p1 = head;
        ListNode* p2 = mid2;
        ListNode* p;
        ListNode* new_head;
        p = new ListNode(0);
        new_head = NULL;
        while (p1 != NULL || p2 != NULL) {
            if (p1 == NULL) {
                p->next = p2;
                p2 = p2->next;
            } else if (p2 == NULL) {
                p->next = p1;
                p1 = p1->next;
            } else {
                if(p1->val > p2->val) {
                    p->next = p2;
                    p2 = p2->next;
                } else {
                    p->next = p1;
                    p1 = p1->next;
                }
            }
            p = p->next;
            if (new_head == NULL) new_head = p;
        }
        return new_head;
    }
};
**/