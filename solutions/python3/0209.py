class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        ans = float('inf')
        sum = 0
        i = 0

        for j in range(len(nums)):
            sum += nums[j]
            while sum >= s:
                ans = min(ans, j - i + 1)
                sum -= nums[i]
                i += 1

        return 0 if ans == float('inf') else ans
