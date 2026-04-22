from typing import List


class Solution:
    def findPoisonedDuration(
        self, time_series: List[int], duration: int
    ) -> int:
        time_series.append(time_series[-1] + duration)

        poisoned_duration = 0

        for i in range(1, len(time_series)):
            poisoned_duration += min(
                duration, time_series[i] - time_series[i - 1]
            )

        return poisoned_duration
