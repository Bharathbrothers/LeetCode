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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(root, sum, curr, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        if (!root) return;
        if (sum == root->val && !root->left && !root->right) {
            curr.push_back(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }

        curr.push_back(root->val);
        dfs(root->left, sum - root->val, curr, ans);
        dfs(root->right, sum - root->val, curr, ans);
        curr.pop_back();
    }
};