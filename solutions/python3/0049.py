class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        map = collections.defaultdict(list)

        for str in strs:
            s = ''.join(sorted(str))
            map[s].append(str)

        for value in map.values():
            ans.append(value)

        return ans
