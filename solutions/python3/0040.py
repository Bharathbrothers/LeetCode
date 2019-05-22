class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        self.dfs(candidates, target, 0, [], ans)
        return ans

    def dfs(self, candidates: List[int], target: int, s: int, path: List[int], ans: List[List[int]]) -> None:
        if target < 0:
            return
        if target == 0:
            ans.append(path)
            return

        for i in range(s, len(candidates)):
            if i > s and candidates[i] == candidates[i - 1]:
                continue
            self.dfs(candidates, target - candidates[i], i + 1, path + [candidates[i]], ans)
