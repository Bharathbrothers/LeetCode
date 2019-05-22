class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        ans = []
        nums.sort()

        for i in range(len(nums) - 2):
            if i == 0 or i > 0 and nums[i] != nums[i - 1]:
                l = i + 1
                r = len(nums) - 1
                target = -nums[i]
                while l < r:
                    if nums[l] + nums[r] == target:
                        ans.append((nums[i], nums[l], nums[r]))
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        l += 1
                        r -= 1
                    elif nums[l] + nums[r] < target:
                        l += 1
                    else:
                        r -= 1

        return ans
