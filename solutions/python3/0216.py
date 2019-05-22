class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        self.dfs(k, n, 1, [], ans)
        return ans

    def dfs(self, k: int, n: int, s: int, path: List[int], ans: List[List[int]]) -> None:
        if n < 0:
            return
        if n == 0:
            if k == 0:
                ans.append(path)
                return

        for i in range(s, 10):
            self.dfs(k - 1, n - i, i + 1, path + [i], ans)
