import heapq
from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = [(x * x + y * y, i) for i, (x, y) in enumerate(points)]
        heapq.heapify(heap)

        return [points[heapq.heappop(heap)[1]] for _ in range(k)]
