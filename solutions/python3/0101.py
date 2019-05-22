# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.helper(root, root)

    def helper(self, p: TreeNode, q: TreeNode) -> bool:
        if not p or not q:
            return p == q
        return p.val == q.val and self.helper(p.left, q.right) and self.helper(p.right, q.left)
