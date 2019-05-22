class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        cut = [0] * n
        dp = [[False for j in range(n)] for i in range(n)]

        for i in range(n):
            _min = i
            for j in range(i + 1):
                if s[j] == s[i] and (j + 1 > i - 1 or dp[j + 1][i - 1]):
                    dp[j][i] = True
                    _min = 0 if j == 0 else min(_min, cut[j - 1] + 1)
            cut[i] = _min

        return cut[n - 1]
