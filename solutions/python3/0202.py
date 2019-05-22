class Solution:
    def isHappy(self, n: int) -> bool:
        slow = self.helper(n)
        fast = self.helper(self.helper(n))

        while slow != fast:
            slow = self.helper(slow)
            fast = self.helper(self.helper(fast))

        if slow == 1:
            return True
        return False

    def helper(self, n: int) -> bool:
        sum = 0

        while n:
            sum += pow(n % 10, 2)
            n //= 10

        return sum
