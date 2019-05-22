# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        return self.helper(0, 0, len(inorder), inorder, postorder)

    def helper(self, i: int, j: int, n: int, inorder: List[int], postorder: List[int]) -> TreeNode:
        if n == 0:
            return None
        root = TreeNode(postorder[j + n - 1])
        if n == 1:
            return root

        k = i
        while inorder[k] != root.val:
            k += 1
        l = k - i

        root.left = self.helper(i, j, l, inorder, postorder)
        root.right = self.helper(
            i + l + 1, j + l, n - l - 1, inorder, postorder)

        return root
