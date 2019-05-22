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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }

private:
    vector<TreeNode*> helper(int min, int max) {
        vector<TreeNode*> ans;
        if (min > max) {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = min; i <= max; i++) {
            vector<TreeNode*> leftTree = helper(min, i - 1);
            vector<TreeNode*> rightTree = helper(i + 1, max);
            for (auto left : leftTree) {
                for (auto right : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};