import heapq
import math
from typing import List


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-gift for gift in gifts]
        heapq.heapify(gifts)

        for _ in range(k):
            heapq.heappush(gifts, -(int(math.sqrt(-heapq.heappop(gifts)))))

        return -sum(gifts)
