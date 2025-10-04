import heapq
from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = [
            ((point[0] ** 2 + point[1] ** 2) ** 0.5, i)
            for i, point in enumerate(points)
        ]
        heapq.heapify(heap)

        closest_points = []

        for _ in range(k):
            closest_points.append(points[heapq.heappop(heap)[1]])

        return closest_points
