class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        self.dfs(nums, len(nums), [False] * len(nums), [], ans)
        return ans

    def dfs(self, nums: List[int], target: int, used: List[bool], path: List[int], ans: List[List[int]]) -> None:
        if target == 0:
            ans.append(path)
            return

        for i in range(len(nums)):
            if used[i] or i > 0 and used[i - 1] and nums[i] == nums[i - 1]:
                continue
            used[i] = True
            self.dfs(nums, target - 1, used, path + [nums[i]], ans)
            used[i] = False
