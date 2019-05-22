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
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }

private:
    int ans = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }
};