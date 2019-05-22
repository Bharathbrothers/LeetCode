# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.helper(root, None, None)

    def helper(self, root: TreeNode, minNode: TreeNode, maxNode: TreeNode) -> bool:
        if not root:
            return True
        if minNode and root.val <= minNode.val or maxNode and root.val >= maxNode.val:
            return False

        return self.helper(root.left, minNode, root) and self.helper(root.right, root, maxNode)
