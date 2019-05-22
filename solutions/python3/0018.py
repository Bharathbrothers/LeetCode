class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        self.nSum(sorted(nums), target, 4, [], ans)
        return ans

    def nSum(self, nums: List[int], target: int, n: int, curr: List[int], ans: List[List[int]]) -> None:
        if len(nums) < n or n < 2 or target < nums[0] * n or target > nums[-1] * n:
            return

        if n == 2:
            l = 0
            r = len(nums) - 1
            while l < r:
                if nums[l] + nums[r] == target:
                    ans.append(curr + [nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                elif nums[l] + nums[r] < target:
                    l += 1
                else:
                    r -= 1
        else:
            for i in range(len(nums) - n + 1):
                if i == 0 or i > 0 and nums[i - 1] != nums[i]:
                    self.nSum(nums[i + 1:], target - nums[i],
                              n - 1, curr + [nums[i]], ans)
