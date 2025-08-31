import heapq
from typing import List


class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        heapq.heapify(prices)

        minTwoChocos = heapq.heappop(prices) + heapq.heappop(prices)
        return money - minTwoChocos if minTwoChocos <= money else money
