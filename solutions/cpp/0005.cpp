class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length() * 2 + 3;

        // Manacher's Algorithm
        string T(len, '#');
        T[0] = '$';
        T[len - 1] = '@';
        for (int i = 2; i < len - 2; i += 2)
            T[i] = s[i / 2 - 1];

        int center = 1;
        int right = 1;
        vector<int> P(len, 0);

        for (int i = 1; i < len - 1; i++) {
            int mirr = 2 * center - i;
            if (i < right) P[i] = min(P[mirr], right - i);
            while (T[i + P[i] + 1] == T[i - P[i] - 1])
                P[i]++;
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }

        // find max and the center;
        int max = 0;
        int c = 0;
        for (int i = 0; i < len; i++)
            if (P[i] > max) {
                max = P[i];
                c = i;
            }

        // omit '#' and get the string desired
        string ans(max, '#');
        int i = 0;
        for (int j = c - max + 1; j < c + max; j += 2) {
            ans[i] = T[j];
            i++;
        }

        return ans;
    }
};