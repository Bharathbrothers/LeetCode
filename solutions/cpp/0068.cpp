class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> curr;
        int numOfLetters = 0;

        for (const auto& word : words) {
            if (numOfLetters + (int)curr.size() + (int)word.length() >
                maxWidth) {
                for (int i = 0; i < maxWidth - numOfLetters; i++) {
                    curr.size() - 1 == 0
                        ? curr[0].append(" ")
                        : curr[i % (curr.size() - 1)].append(" ");
                }
                ans.push_back(join(curr, ""));
                curr.clear();
                numOfLetters = 0;
            }
            curr.push_back(word);
            numOfLetters += word.length();
        }
        ans.push_back(ljust(join(curr, " "), maxWidth));

        return ans;
    }

private:
    string join(const vector<string>& v, const string c) {
        string s;
        for (auto p = v.begin(); p != v.end(); p++) {
            s += *p;
            if (p != v.end() - 1) s += c;
        }
        return s;
    }

    string ljust(string s, int width) {
        for (int i = 0; i < s.size() - width; i++) s += " ";
        return s;
    }
};