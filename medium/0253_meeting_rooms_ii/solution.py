import heapq
from typing import List

from utils.python.interval import Interval


class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key=lambda interval: interval.start)

        heap = []
        max_rooms = 0

        for interval in intervals:
            if heap and interval.start >= heap[0]:
                heapq.heappop(heap)

            heapq.heappush(heap, interval.end)

            if len(heap) > max_rooms:
                max_rooms = len(heap)

        return max_rooms
