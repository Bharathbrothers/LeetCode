class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("", n, n, ans);
        return ans;
    }

private:
    void helper(string str, int l, int r, vector<string>& ans) {
        if (l == 0 && r == 0) ans.push_back(str);
        if (l > 0) helper(str + '(', l - 1, r, ans);
        if (l < r) helper(str + ')', l, r - 1, ans);
    }
};