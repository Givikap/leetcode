from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        sell = -1

        for buy in range(len(prices) - 1):
            if buy < sell:
                continue

            if prices[buy] >= prices[buy+1]:
                continue
            else:
                for sell in range(buy + 1, len(prices)):
                    if prices[sell-1] < prices[sell]:
                        break

                profit += prices[sell] - prices[buy]

        return profit