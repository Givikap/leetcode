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

        landFt = sum(
            min(zip(landStartTime, landDuration), key=lambda t: t[0] + t[1])
        )
        for waterSt, waterDur in zip(waterStartTime, waterDuration):
            earliestFinishTime = min(
                earliestFinishTime, max(landFt, waterSt) + waterDur
            )

        waterFt = sum(
            min(zip(waterStartTime, waterDuration), key=lambda t: t[0] + t[1])
        )
        for landSt, landDur in zip(landStartTime, landDuration):
            earliestFinishTime = min(
                earliestFinishTime, max(waterFt, landSt) + landDur
            )

        return earliestFinishTime
