class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        self.dfs(nums, len(nums), 0, [], ans)
        return ans

    def dfs(self, nums: List[int], target: int, s: int, path: List[int], ans: List[List[int]]) -> None:
        if target < 0:
            return

        ans.append(path)

        for i in range(s, len(nums)):
            if i > s and nums[i] == nums[i - 1]:
                continue
            self.dfs(nums, target - 1, i + 1, path + [nums[i]], ans)
