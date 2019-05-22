class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.length();
        const int n = t.length();

        vector<vector<long>> dp(m + 1, vector<long>(n + 1));

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] +
                               (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }

        return dp[m][n];
    }
};