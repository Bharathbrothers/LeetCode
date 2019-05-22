# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from heapq import heappush, heappop


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = ListNode(0)
        curr = dummy
        heap = []

        for i in range(len(lists)):
            if lists[i]:
                heappush(heap, (lists[i].val, i, lists[i]))

        while heap:
            node = heappop(heap)
            curr.next = node[2]
            curr = curr.next
            if curr.next:
                heappush(heap, (curr.next.val, node[1], curr.next))

        return dummy.next
