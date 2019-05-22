class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] && p[j - 1] == '*';
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] && s[i - 1] == '*';
                else
                    dp[i][j] =
                        (dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1]) &&
                            (s[i - 1] == '*' || p[j - 1] == '*') ||
                        (dp[i - 1][j - 1]) &&
                            (s[i - 1] == '?' || p[j - 1] == '?' ||
                             s[i - 1] == p[j - 1]);
            }
        }

        return dp[m][n];
    }
};