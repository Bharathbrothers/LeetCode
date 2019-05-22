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
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;

        int len = 0;
        for (auto curr = head; curr; curr = curr->next) len++;

        auto prev = dummy;
        auto curr = head;
        for (int i = 0; i < len / k; i++) {
            for (int j = 0; j < k - 1; j++) {
                auto next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
        }

        return dummy->next;
    }
};