class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> map;

        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            if (map.count(c)) i = max(i, map[c]);
            ans = max(ans, j - i + 1);
            map[c] = j + 1;
        }

        return ans;
    }
};