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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(0, 0, inorder.size(), inorder, postorder);
    }

private:
    TreeNode* helper(int i, int j, int n, vector<int>& inorder, vector<int>& postorder) {
        if (n == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[j + n - 1]);
        if (n == 1) return root;

        int k = i;
        while (inorder[k] != root->val) k++;
        int l = k - i;

        root->left = helper(i, j, l, inorder, postorder);
        root->right = helper(i + l + 1, j + l, n - l - 1, inorder, postorder);

        return root;
    }
};