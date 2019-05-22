"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        node = root
        curr = Node(None, None, None, None)
        prev = curr

        while node:
            while node:
                curr.next = node.left
                curr = curr.next or curr
                curr.next = node.right
                curr = curr.next or curr
                node = node.next
            node = prev.next
            curr = prev

        return root
