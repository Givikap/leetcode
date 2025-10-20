from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], new_interval: List[int]
    ) -> List[List[int]]:
        new_intervals = []
        i = 0

        while i < len(intervals) and intervals[i][1] < new_interval[0]:
            new_intervals.append(intervals[i])
            i += 1

        while i < len(intervals) and intervals[i][0] <= new_interval[1]:
            new_interval = [
                min(new_interval[0], intervals[i][0]),
                max(new_interval[1], intervals[i][1]),
            ]
            i += 1

        new_intervals.append(new_interval)

        while i < len(intervals):
            new_intervals.append(intervals[i])
            i += 1

        return new_intervals
