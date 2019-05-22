# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.dfs(root, 0)
        return self.ans

    ans = 0

    def dfs(self, root: TreeNode, path: int) -> None:
        if not root:
            return
        if not root.left and not root.right:
            self.ans += (path * 10 + root.val)
            return

        self.dfs(root.left, path * 10 + root.val)
        self.dfs(root.right, path * 10 + root.val)
