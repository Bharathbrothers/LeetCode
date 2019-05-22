class Solution {
public:
    string countAndSay(int n) {
        unordered_map<int, string> map = {{1, "1"}, {2, "11"}, {3, "21"}, {4, "1211"}, {5, "111221"}};
        if (n <= 5) return map[n];

        for (int i = 6; i < n + 1; i++) {
            string s;
            int j = 0;
            while (j <= map[i - 1].size() - 2) {
                int count = 1;
                while (j <= map[i - 1].size() - 2 &&
                       map[i - 1][j] == map[i - 1][j + 1]) {
                    count++;
                    j++;
                }
                s += to_string(count) + map[i - 1][j];
                j++;
            }
            if (j == map[i - 1].size() - 1) s += to_string(1) + map[i - 1][j];
            map[i] = s;
        }

        return map[n];
    }
};