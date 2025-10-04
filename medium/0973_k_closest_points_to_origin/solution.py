import heapq
from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        closest_points = []

        for i, point in enumerate(points):
            heap.append(((point[0] ** 2 + point[1] ** 2) ** 0.5, i))

        heapq.heapify(heap)

        for i in range(k):
            closest_points.append(points[heapq.heappop(heap)[1]])

        return closest_points
