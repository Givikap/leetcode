from typing import List


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        uncoveredIntervalsCount = 1
        prevInterval = intervals[0]

        for i in range(1, len(intervals)):
            if (
                intervals[i][0] >= prevInterval[0]
                and intervals[i][1] <= prevInterval[1]
            ):
                pass
            elif (
                intervals[i][0] <= prevInterval[0]
                and intervals[i][1] >= prevInterval[1]
            ):
                prevInterval = intervals[i]
            else:
                uncoveredIntervalsCount += 1
                prevInterval = intervals[i]

        return uncoveredIntervalsCount
