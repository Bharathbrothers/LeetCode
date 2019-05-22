class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = ''
        nums = [i + 1 for i in range(n)]
        fact = [1] * n

        for i in range(1, n):
            fact[i] = fact[i - 1] * i

        k -= 1

        for i in range(n, 0, -1):
            j = k // fact[i - 1]
            k %= fact[i - 1]
            ans += str(nums[j])
            nums.pop(j)

        return ans
