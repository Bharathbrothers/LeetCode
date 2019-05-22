class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = float('inf')
        ans = 0

        for i in range(len(prices)):
            minPrice = min(minPrice, prices[i])
            ans = max(ans, prices[i] - minPrice)

        return ans
