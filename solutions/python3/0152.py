class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        _max = ans
        _min = ans

        for i in range(1, len(nums)):
            if nums[i] < 0:
                _max, _min = _min, _max
            _max = max(nums[i], _max * nums[i])
            _min = min(nums[i], _min * nums[i])
            ans = max(ans, _max)

        return ans
