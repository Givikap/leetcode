import heapq
from typing import List


class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        heapq.heapify(prices)

        min_two_chocos = heapq.heappop(prices) + heapq.heappop(prices)
        return money - min_two_chocos if min_two_chocos <= money else money
