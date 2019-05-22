class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}

        for i in range(len(nums)):
            if nums[i] in map:
                return map[nums[i]], i
            map[target - nums[i]] = i

        return -1, -1
