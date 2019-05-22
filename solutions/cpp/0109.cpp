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
        int len = 0;
        for (auto curr = head; curr; curr = curr->next) len++;
        this->head = head;
        return helper(0, len - 1);
    }

private:
    ListNode* head;

    TreeNode* helper(int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) >> 1;

        TreeNode* left = helper(l, mid - 1);
        TreeNode* node = new TreeNode(head->val);
        head = head->next;
        node->left = left;
        node->right = helper(mid + 1, r);

        return node;
    }
};