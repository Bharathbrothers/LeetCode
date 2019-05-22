class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zero = 0
        two = len(nums) - 1

        for i in range(two + 1):
            while nums[i] == 2 and i < two:
                nums[i], nums[two] = nums[two], nums[i]
                two -= 1
            while nums[i] == 0 and i > zero:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1
