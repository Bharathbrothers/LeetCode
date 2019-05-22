class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        if len(s) == 1:
            return 1

        dp = [1, 1, 0]

        for i in range(1, len(s)):
            dp[2] = 0
            if not self.isValid(s[i]) and not self.isValid(s[i - 1], s[i]):
                return 0
            if self.isValid(s[i]):
                dp[2] += dp[0]
            if self.isValid(s[i - 1], s[i]):
                dp[2] += dp[1]
            dp[1] = dp[0]
            dp[0] = dp[2]

        return dp[2]

    def isValid(self, a: chr, b=None) -> bool:
        if b:
            return a == '1' or (a == '2' and b <= '6')
        return a != '0'
