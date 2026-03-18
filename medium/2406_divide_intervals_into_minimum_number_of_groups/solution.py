import heapq
from typing import List


class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        rooms = []

        for start, end in sorted(intervals):
            if rooms and rooms[0] < start:
                heapq.heappop(rooms)
            heapq.heappush(rooms, end)

        return len(rooms)
