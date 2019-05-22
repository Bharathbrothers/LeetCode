# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ans = []
        self.dfs(root, sum, [], ans)
        return ans

    def dfs(self, root: TreeNode, sum: int, curr: List[int], ans: List[List[int]]) -> None:
        if not root:
            return
        if sum == root.val and not root.left and not root.right:
            ans.append(curr + [root.val])
            return

        self.dfs(root.left, sum - root.val, curr + [root.val], ans)
        self.dfs(root.right, sum - root.val, curr + [root.val], ans)
