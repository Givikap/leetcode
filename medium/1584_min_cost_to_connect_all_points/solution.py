import heapq
from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        visited = set()
        heap = []

        min_cost = 0
        curr = 0

        while len(visited) != len(points):
            visited.add(tuple(points[curr]))

            for i, point in enumerate(points):
                if points[curr] == point:
                    continue

                heapq.heappush(heap, (
                    abs(points[curr][0] - point[0]) + abs(points[curr][-1] - point[1]),
                    tuple(points[curr]),
                    tuple(point),
                    i
                ))

            while heap:
                distance, p1, p2, i = heapq.heappop(heap)

                if not (p1 in visited and p2 in visited):
                    visited.add(p2)

                    min_cost += distance
                    curr = i
                    break

        return min_cost 