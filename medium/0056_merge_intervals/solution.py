import heapq
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        heapq.heapify(intervals)
        merged_intervals = []

        while len(intervals) > 1:
            interval1 = heapq.heappop(intervals)
            interval2 = intervals[0]

            if interval1[1] >= interval2[0]:
                heapq.heappop(intervals)
                heapq.heappush(intervals, [interval1[0], max(interval1[1], interval2[1])])
            else:
                merged_intervals.append(interval1)

        if intervals:
            merged_intervals.append(intervals[0])

        return merged_intervals
