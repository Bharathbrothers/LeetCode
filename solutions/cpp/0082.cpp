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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(NULL);
        ListNode* prev = dummy;
        dummy->next = head;

        while (head) {
            while (head->next && head->val == head->next->val)
                head = head->next;
            if (prev->next == head)
                prev = prev->next;
            else
                prev->next = head->next;
            head = head->next;
        }

        return dummy->next;
    }
};