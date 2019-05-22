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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    Solution(ListNode* head) {
        privateHead = head;
        for (auto curr = head; curr; curr = curr->next) len++;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % len;
        ListNode* curr = privateHead;
        while (n-- > 0) curr = curr->next;
        return curr->val;
    }

private:
    ListNode* privateHead;
    int len = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */