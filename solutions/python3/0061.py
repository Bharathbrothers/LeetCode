# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or k == 0:
            return head

        len = 0
        curr = head
        while curr:
            len += 1
            curr = curr.next

        k %= len
        if k == 0:
            return head

        slow = head
        fast = head

        for _ in range(k):
            fast = fast.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next

        ans = slow.next
        slow.next = None
        fast.next = head

        return ans
