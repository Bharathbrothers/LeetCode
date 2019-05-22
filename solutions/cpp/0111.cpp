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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            ans++;
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                if (!node->left && !node->right) return ans;
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
        }

        return -1;
    }
};