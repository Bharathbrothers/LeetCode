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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k, NULL);
        int len = 0;
        for (auto curr = root; curr; curr = curr->next) len++;
        int l = len / k;
        int r = len % k;

        ListNode* head = root;
        ListNode* prev = NULL;

        for (int i = 0; i < k; i++, r--) {
            ans[i] = head;
            for (int j = 0; j < l + (r > 0); j++) {
                prev = head;
                head = head->next;
            }
            if (prev) prev->next = NULL;
        }

        return ans;
    }
};