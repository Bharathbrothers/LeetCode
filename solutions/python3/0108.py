# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.helper(nums, 0, len(nums) - 1)

    def helper(self, nums: List[int], l: int, r: int) -> TreeNode:
        if l > r:
            return None

        mid = (l + r) >> 1
        root = TreeNode(nums[mid])
        root.left = self.helper(nums, l, mid - 1)
        root.right = self.helper(nums, mid + 1, r)

        return root
