class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)

        if endWord not in wordSet:
            return 0

        ans = 0
        wordLen = len(beginWord)
        queue1 = set([beginWord])
        queue2 = set([endWord])

        while queue1 and queue2:
            ans += 1

            if len(queue1) > len(queue2):
                queue1, queue2 = queue2, queue1

            queue = set()
            for word in queue1:
                for i in range(wordLen):
                    for j in string.ascii_lowercase:
                        newWord = word[:i] + j + word[i + 1:]
                        if newWord in queue2:
                            return ans + 1
                        if newWord not in wordSet:
                            continue
                        wordSet.remove(newWord)
                        queue.add(newWord)
            queue, queue1 = queue1, queue

        return 0
