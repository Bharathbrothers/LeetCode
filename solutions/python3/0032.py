class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans = 0
        left = 0
        right = 0

        for i in range(len(s)):
            if s[i] == '(':
                left += 1
            else:
                right += 1
            if left == right:
                ans = max(ans, 2 * right)
            elif right > left:
                left = 0
                right = 0

        left = 0
        right = 0

        for i in range(len(s) - 1, -1, -1):
            if s[i] == '(':
                left += 1
            else:
                right += 1
            if left == right:
                ans = max(ans, 2 * left)
            elif left > right:
                left = 0
                right = 0

        return ans
