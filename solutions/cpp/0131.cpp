class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(s, 0, path, ans);
        return ans;
    }

private:
    void dfs(string& s, int j, vector<string>& path, vector<vector<string>>& ans) {
        if (j == s.length()) {
            ans.push_back(path);
            return;
        }

        for (int i = j; i < s.length(); i++)
            if (isPalindrome(s, j, i)) {
                path.push_back(s.substr(j, i - j + 1));
                dfs(s, i + 1, path, ans);
                path.pop_back();
            }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};