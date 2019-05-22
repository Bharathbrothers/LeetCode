class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;

        unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        ans.push_back("");
        for (const char& i : digits) {
            vector<string> tmp;
            for (const string& j : ans)
                for (const char& k : map[i])
                    tmp.push_back(j + k);
            ans = tmp;
        }

        return ans;
    }
};