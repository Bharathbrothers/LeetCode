class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        l = 1
        r = max(piles) + 1

        while l < r:
            m = (l + r) >> 1
            hour = 0
            for pile in piles:
                hour += (pile - 1) // m + 1
            if hour <= H:
                r = m
            else:
                l = m + 1

        return l
