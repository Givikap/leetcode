from typing import List


class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        earliestFinishTime = float("inf")

        earliestLandFinishTime = sum(
            min(zip(landStartTime, landDuration), key=lambda t: t[0] + t[1])
        )
        earliestWaterFinishTime = sum(
            min(zip(waterStartTime, waterDuration), key=lambda t: t[0] + t[1])
        )

        earliestFinishTime = float("inf")

        for landSt, landDur in zip(landStartTime, landDuration):
            earliestFinishTime = min(
                earliestFinishTime,
                max(earliestWaterFinishTime, landSt) + landDur,
            )

        for waterSt, waterDur in zip(waterStartTime, waterDuration):
            earliestFinishTime = min(
                earliestFinishTime,
                max(earliestLandFinishTime, waterSt) + waterDur,
            )

        return earliestFinishTime
