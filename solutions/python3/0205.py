class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map_s = {}
        map_t = {}
        map_s = collections.defaultdict(lambda: 0, map_s)
        map_t = collections.defaultdict(lambda: 0, map_t)

        for i in range(len(s)):
            if map_s[s[i]] != map_t[t[i]]:
                return False
            map_s[s[i]] = i + 1
            map_t[t[i]] = i + 1

        return True
