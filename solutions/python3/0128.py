class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        numsSet = set(nums)

        for num in numsSet:
            if num - 1 not in numsSet:
                currNum = num
                currAns = 1
                while currNum + 1 in numsSet:
                    currNum += 1
                    currAns += 1
                ans = max(ans, currAns)

        return ans
