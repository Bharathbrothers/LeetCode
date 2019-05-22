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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            vector<int> currLevel;
            int currLevelSize = queue.size();
            for (int i = 0; i < currLevelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                currLevel.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            ans.insert(ans.begin(), currLevel);
        }

        return ans;
    }
};