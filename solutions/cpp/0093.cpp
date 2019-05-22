class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> path(4);
        dfs(s, 0, 0, path, ans);
        return ans;
    }

    void dfs(string s, int depth, int index, vector<string>& path, vector<string>& ans) {
        if (depth == 4 && index == s.length()) {
            ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }
        if (depth == 4 || index == s.length()) return;

        for (int i = 1; i <= 3; ++i) {
            if (index + i > s.length()) return;
            if (i > 1 && s[index] == '0') return;
            string temp = s.substr(index, i);
            if (stoi(temp) > 255) return;
            path[depth] = temp;
            dfs(s, depth + 1, index + i, path, ans);
            path[depth] = "";
        }
    }
};