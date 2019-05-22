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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int path = 0;
        dfs(root, path, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int& path, int& ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            path = path * 10 + root->val;
            ans += path;
            path = (path - root->val) / 10;
            return;
        }

        path = path * 10 + root->val;
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
        path = (path - root->val) / 10;
    }
};