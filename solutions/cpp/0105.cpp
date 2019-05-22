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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, preorder.size(), preorder, inorder);
    }

private:
    TreeNode* helper(int i, int j, int n, vector<int>& preorder, vector<int>& inorder) {
        if (n == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        if (n == 1) return root;

        int k = j;
        while (inorder[k] != root->val) k++;
        int l = k - j;

        root->left = helper(i + 1, j, l, preorder, inorder);
        root->right = helper(i + l + 1, j + l + 1, n - l - 1, preorder, inorder);

        return root;
    }
};