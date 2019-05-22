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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            ans++;
            TreeNode* node = queue.front();
            queue.pop();
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }

        return ans;
    }
};