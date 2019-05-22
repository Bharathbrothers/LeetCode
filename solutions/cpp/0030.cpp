class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};

        vector<int> ans;
        unordered_map<string, int> map;
        for (const auto& word : words) map[word]++;

        const int m = s.size();
        const int wordLen = words[0].size();
        for (int i = 0; i < wordLen; i++) {
            int index = i;
            int count = 0;
            unordered_map<string, int> tempMap;

            for (int j = i; j <= m - wordLen; j += wordLen) {
                string str = s.substr(j, wordLen);
                if (map.count(str)) {
                    tempMap[str]++;
                    count++;
                    while (tempMap[str] > map[str]) {
                        tempMap[s.substr(index, wordLen)]--;
                        count--;
                        index += wordLen;
                    }
                    if (count == words.size()) {
                        ans.push_back(index);
                        tempMap[s.substr(index, wordLen)]--;
                        count--;
                        index += wordLen;
                    }
                } else {
                    tempMap.clear();
                    count = 0;
                    index = j + wordLen;
                }
            }
        }

        return ans;
    }
};