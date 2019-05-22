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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;

        ListNode* dummyOdd = new ListNode(NULL);
        ListNode* dummyEven = new ListNode(NULL);
        ListNode* prevOdd = dummyOdd;
        ListNode* prevEven = dummyEven;
        int index = 0;

        while (head) {
            auto next = head->next;
            head->next = NULL;
            if (index++ & 1) {
                prevEven->next = head;
                prevEven = head;
            } else {
                prevOdd->next = head;
                prevOdd = head;
            }
            head = next;
        }
        prevOdd->next = dummyEven->next;

        return dummyOdd->next;
    }
};