class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyOne = float('inf')
        buyTwo = float('inf')
        sellOne = 0
        sellTwo = 0

        for price in prices:
            buyOne = min(buyOne, price)
            sellOne = max(sellOne, price - buyOne)
            buyTwo = min(buyTwo, price - sellOne)
            sellTwo = max(sellTwo, price - buyTwo)

        return sellTwo
