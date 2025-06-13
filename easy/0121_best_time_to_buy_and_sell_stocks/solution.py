from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0

        for i1 in range(len(prices)):
            for i2 in range(len(prices)):
                if i1 == i2 or i1 > i2:
                    continue

                if prices[i2] - prices[i1] > max_profit:
                    max_profit = prices[i2] - prices[i1]

        return max_profit