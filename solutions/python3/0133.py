"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        if node not in self.ans:
            self.ans[node] = Node(node.val, [])
            for neighbor in node.neighbors:
                self.ans[node].neighbors.append(self.cloneGraph(neighbor))

        return self.ans[node]

    ans = {}
