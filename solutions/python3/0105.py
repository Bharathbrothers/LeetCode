# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.helper(0, 0, len(preorder), preorder, inorder)

    def helper(self, i: int, j: int, n: int, preorder: List[int], inorder: List[int]) -> TreeNode:
        if n == 0:
            return None
        root = TreeNode(preorder[i])
        if n == 1:
            return root

        k = j
        while inorder[k] != root.val:
            k += 1
        l = k - j

        root.left = self.helper(i + 1, j, l, preorder, inorder)
        root.right = self.helper(i + l + 1, j + l + 1,
                                 n - l - 1, preorder, inorder)

        return root
