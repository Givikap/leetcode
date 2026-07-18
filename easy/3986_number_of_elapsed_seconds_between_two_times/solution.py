from datetime import time


class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        startTs = time.fromisoformat(startTime)
        endTs = time.fromisoformat(endTime)

        return (
            3600 * (endTs.hour - startTs.hour)
            + 60 * (endTs.minute - startTs.minute)
            + (endTs.second - startTs.second)
        )
