class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        self.dfs(s, 0, 0, [""] * 4, ans)
        return ans

    def dfs(self, s: str, depth: int, index: int, path: List[str], ans: List[str]) -> None:
        if depth == 4 and index == len(s):
            ans.append(".".join(path))
            return
        if depth == 4 or index == len(s):
            return

        for i in range(1, 4):
            if index + i > len(s):
                return
            if i > 1 and s[index] == '0':
                return
            temp = s[index: index + i]
            if int(temp) > 255:
                return
            path[depth] = temp
            self.dfs(s, depth + 1, index + i, path, ans)
            path[depth] = ""
