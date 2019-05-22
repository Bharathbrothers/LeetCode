# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(None)
        curr = dummy
        carry = 0

        while carry or l1 or l2:
            carry += (l1.val if l1 else 0) + (l2.val if l2 else 0)
            curr.next = ListNode(carry % 10)
            curr = curr.next
            carry //= 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next
