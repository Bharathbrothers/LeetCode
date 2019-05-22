# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 1:
            return head

        dummy = ListNode(None)
        dummy.next = head

        len = 0
        curr = head
        while curr:
            len += 1
            curr = curr.next

        prev = dummy
        curr = head
        for i in range(len // k):
            for j in range(k - 1):
                next = curr.next
                curr.next = next.next
                next.next = prev.next
                prev.next = next
            prev = curr
            curr = curr.next

        return dummy.next
