class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;

        for (int i = 0; i < s.length(); i++) {
            if (map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }

        return true;
    }
};