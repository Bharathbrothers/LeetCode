class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        vector<int> dp = {1, 1, 0};

        for (int i = 1; i < s.length(); i++) {
            dp[2] = 0;
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
            if (isValid(s[i])) dp[2] += dp[0];
            if (isValid(s[i - 1], s[i])) dp[2] += dp[1];
            dp[1] = dp[0];
            dp[0] = dp[2];
        }

        return dp[2];
    }

private:
    bool isValid(char a, char b) { return a == '1' || (a == '2' && b <= '6'); }
    bool isValid(char a) { return a != '0'; }
};