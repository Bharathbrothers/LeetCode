# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def flatten(self, root: TreeNode) -> None:
        if not root:
            return

        self.flatten(root.right)
        self.flatten(root.left)
        root.right = self.next
        root.left = None
        self.next = root

    next = None
