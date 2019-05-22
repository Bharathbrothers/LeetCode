class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        map = collections.Counter(t)
        required = len(map)

        l = 0
        r = 0
        bestLeft = 0
        bestRight = 0
        windowLen = len(s) + 1

        for r in range(len(s)):
            if s[r] in map:
                map[s[r]] -= 1
                if map[s[r]] == 0:
                    required -= 1

            while required == 0 and l <= r:
                if r - l + 1 < windowLen:
                    windowLen = r - l + 1
                    bestLeft = l
                    bestRight = r

                if s[l] in map:
                    map[s[l]] += 1
                    if map[s[l]] > 0:
                        required += 1

                l += 1

        return "" if windowLen == len(s) + 1 else s[bestLeft: bestRight + 1]
