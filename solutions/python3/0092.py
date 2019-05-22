# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if not head:
            return None

        prev = None
        curr = head

        for _ in range(m - 1):
            prev = curr
            curr = curr.next

        conn = prev
        tail = curr

        for _ in range(n - m + 1):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        if conn:
            conn.next = prev
        else:
            head = prev
        tail.next = curr

        return head
