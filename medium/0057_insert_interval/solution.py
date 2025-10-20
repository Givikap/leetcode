from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], new_interval: List[int]
    ) -> List[List[int]]:
        if not intervals:
            return [new_interval]

        left, right = 0, len(intervals) - 1

        if intervals[0][0] > new_interval[0]:
            left = right + 1
            mid = 0

            intervals.insert(0, new_interval)
        elif intervals[-1][1] < new_interval[0]:
            left = right + 1
            mid = len(intervals) - 1

            intervals.append(new_interval)
        else:
            while left <= right:
                mid = (left + right) // 2

                if (
                    intervals[mid][0] <= new_interval[0]
                    and intervals[mid][1] >= new_interval[0]
                ):
                    intervals[mid][0] = min(intervals[mid][0], new_interval[0])
                    intervals[mid][1] = max(intervals[mid][1], new_interval[1])

                    break

                elif intervals[mid][1] < new_interval[0]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                intervals.insert(left, new_interval)
                mid = left

        while (
            mid < len(intervals) - 1
            and intervals[mid][1] >= intervals[mid + 1][0]
        ):
            intervals[mid][1] = max(
                intervals[mid][1], intervals.pop(mid + 1)[1]
            )

        return intervals
