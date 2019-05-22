# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.helper(root)
        return self.ans

    ans = float('-inf')

    def helper(self, root: TreeNode) -> int:
        if not root:
            return 0

        left = max(self.helper(root.left), 0)
        right = max(self.helper(root.right), 0)
        self.ans = max(self.ans, root.val + left + right)

        return root.val + max(left, right)
