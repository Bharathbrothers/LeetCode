class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid or obstacleGrid[0][0]:
            return 0

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        dp = [[0 for j in range(n)] for i in range(m)]
        dp[0][0] = 1

        for i in range(1, m):
            if not obstacleGrid[i][0]:
                dp[i][0] = dp[i - 1][0]

        for j in range(1, n):
            if not obstacleGrid[0][j]:
                dp[0][j] = dp[0][j - 1]

        for i in range(1, m):
            for j in range(1, n):
                if not obstacleGrid[i][j]:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m - 1][n - 1]
