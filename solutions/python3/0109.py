# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        len = self.getLength(head)

        def helper(l, r):
            nonlocal head

            if l > r:
                return None

            mid = (l + r) >> 1
            left = helper(l, mid - 1)
            node = TreeNode(head.val)
            head = head.next
            node.left = left
            node.right = helper(mid + 1, r)

            return node

        return helper(0, len - 1)

    def getLength(self, head: ListNode) -> int:
        curr = head
        len = 0
        while curr:
            len += 1
            curr = curr.next
        return len
