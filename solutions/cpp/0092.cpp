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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;

        for (int i = 0; i < m - 1; i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* conn = prev;
        ListNode* tail = curr;

        for (int i = 0; i < n - m + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (conn)
            conn->next = prev;
        else
            head = prev;
        tail->next = curr;

        return head;
    }
};