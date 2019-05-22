class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0]) return 0;

        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        vector<vector<long>> dp(m, vector<long>(n));
        dp[0][0] = 1;

        for (int i = 1; i < m; i++)
            if (!obstacleGrid[i][0])
                dp[i][0] = dp[i - 1][0];

        for (int j = 1; j < n; j++)
            if (!obstacleGrid[0][j])
                dp[0][j] = dp[0][j - 1];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (!obstacleGrid[i][j])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};