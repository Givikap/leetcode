from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        i_buy = 0

        while i_buy < len(prices) - 1:
            while i_buy < len(prices) - 1 and prices[i_buy] >= prices[i_buy+1]:
                i_buy += 1

            i_sell = i_buy + 1
            next_i_buy = i_sell + 1

            for i_sell in range(i_buy + 1, len(prices)):
                if prices[i_sell] - prices[i_buy] > max_profit:
                    max_profit = prices[i_sell] - prices[i_buy]

            i_buy = next_i_buy

        return max_profit