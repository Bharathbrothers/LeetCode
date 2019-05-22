class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> map;
        for (const char& c : t) map[c]++;
        int required = map.size();

        int l = 0;
        int r = 0;
        int bestLeft = 0;
        int bestRight = 0;
        int windowLen = s.length() + 1;

        for (int r = 0; r < s.length(); r++) {
            if (map.count(s[r]))
                if (--map[s[r]] == 0)
                    required--;

            while (required == 0 && l <= r) {
                if (r - l + 1 < windowLen) {
                    windowLen = r - l + 1;
                    bestLeft = l;
                    bestRight = r;
                }

                if (map.count(s[l]))
                    if (++map[s[l]] > 0)
                        required++;

                l++;
            }
        }

        return windowLen == s.length() + 1 ? "" : s.substr(bestLeft, windowLen);
    }
};