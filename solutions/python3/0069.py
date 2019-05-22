class Solution:
    def mySqrt(self, x: int) -> int:
        l = 0
        r = x + 1

        while l < r:
            m = (l + r) >> 1
            if m * m > x:
                r = m
            else:
                l = m + 1

        return l - 1
