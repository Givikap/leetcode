import heapq
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        heapq.heapify(intervals)
        merged_intervals = []

        curr = heapq.heappop(intervals)
        while intervals:
            next = heapq.heappop(intervals)

            if curr[1] >= next[0]:
                curr[1] = max(curr[1], next[1])
            else:
                merged_intervals.append(curr)
                curr = next

        merged_intervals.append(curr)
        return merged_intervals
