class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        stack = [-1]

        for i in range(len(heights) + 1):
            while stack[-1] != -1 and (i == len(heights) or heights[i] < heights[stack[-1]]):
                h = heights[stack.pop()]
                ans = max(ans, h * (i - stack[-1] - 1))
            stack.append(i)

        return ans
