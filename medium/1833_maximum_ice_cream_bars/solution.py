from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        iceCreamCount = 0

        for cost in sorted(costs):
            if cost > coins:
                break

            coins -= cost
            iceCreamCount += 1

        return iceCreamCount
