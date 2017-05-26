/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        ListNode *slow, *fast, *pre;
        pre = new ListNode(0);
        pre->next = head;
        slow = head;
        fast = head->next;
        while (fast && fast->next) {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        pre->next = NULL;
        TreeNode *right = (slow->next == NULL) ? NULL : sortedListToBST(slow->next);
        TreeNode *left = (slow == head) ? NULL : sortedListToBST(head);
        root->left = left;
        root->right = right;
        return root;
    }
};