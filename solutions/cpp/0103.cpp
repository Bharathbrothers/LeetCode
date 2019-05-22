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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        deque<TreeNode*> deque;
        deque.push_back(root);
        bool isLeftToRight = true;

        while (!deque.empty()) {
            vector<int> currLevel;
            int currLevelSize = deque.size();
            for (int i = 0; i < currLevelSize; i++) {
                if (isLeftToRight) {
                    TreeNode* node = deque.front();
                    deque.pop_front();
                    currLevel.push_back(node->val);
                    if (node->left) deque.push_back(node->left);
                    if (node->right) deque.push_back(node->right);
                } else {
                    TreeNode* node = deque.back();
                    deque.pop_back();
                    currLevel.push_back(node->val);
                    if (node->right) deque.push_front(node->right);
                    if (node->left) deque.push_front(node->left);
                }
            }
            ans.push_back(currLevel);
            isLeftToRight = !isLeftToRight;
        }

        return ans;
    }
};