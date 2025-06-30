import heapq
from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        visited = set()
        heap = []

        min_cost = 0
        curr = 0

        while len(visited) != len(points):
            visited.add(curr)

            for i, point in enumerate(points):
                if curr == i or (curr in visited and i in visited):
                    continue

                heapq.heappush(heap, (
                    abs(points[curr][0] - point[0]) + abs(points[curr][1] - point[1]),
                    (curr, i)
                ))

            while heap:
                distance, (i1, i2) = heapq.heappop(heap)

                if not (i1 in visited and i2 in visited):
                    visited.add(i2)
                    min_cost += distance
                    curr = i2
                    break

        return min_cost 