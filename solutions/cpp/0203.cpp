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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(NULL);
        ListNode* curr = dummy;
        dummy->next = head;

        while (curr) {
            ListNode* next = curr->next;
            while (next && next->val == val) next = next->next;
            curr->next = next;
            curr = next;
        }

        return dummy->next;
    }
};