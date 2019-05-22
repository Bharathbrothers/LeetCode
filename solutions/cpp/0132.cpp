class Solution {
public:
    int minCut(string s) {
        const int n = s.length();
        vector<int> cut(n);
        vector<vector<bool>> dp(n, vector<bool>(n));

        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = 0; j <= i; j++)
                if (s[j] == s[i] && (j + 1 > i - 1 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    min = j == 0 ? 0 : std::min(min, cut[j - 1] + 1);
                }
            cut[i] = min;
        }

        return cut[n - 1];
    }
};