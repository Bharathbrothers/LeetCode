class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());

        if (!set.count(endWord)) return 0;

        int ans = 0;
        int len = beginWord.length();
        unordered_set<string> queue1{beginWord};
        unordered_set<string> queue2{endWord};

        while (!queue1.empty() && !queue2.empty()) {
            ans++;

            if (queue1.size() > queue2.size()) swap(queue1, queue2);

            unordered_set<string> queue;
            for (string word : queue1) {
                for (int i = 0; i < len; i++) {
                    char c = word[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (queue2.count(word)) return ans + 1;
                        if (!set.count(word)) continue;
                        set.erase(word);
                        queue.insert(word);
                    }
                    word[i] = c;
                }
            }
            swap(queue, queue1);
        }

        return 0;
    }
};