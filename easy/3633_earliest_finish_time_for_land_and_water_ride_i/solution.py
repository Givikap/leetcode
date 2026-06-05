from typing import List


class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        landTime = sorted(
            zip(landStartTime, landDuration), key=lambda t: t[0] + t[1]
        )
        waterTime = sorted(
            zip(waterStartTime, waterDuration), key=lambda t: t[0] + t[1]
        )

        earliestFinishTime = float("inf")

        landFt = landTime[0][0] + landTime[0][1]
        for waterSt, waterDur in waterTime:
            earliestFinishTime = min(
                earliestFinishTime, max(landFt, waterSt) + waterDur
            )

        waterFt = waterTime[0][0] + waterTime[0][1]
        for landSt, landDur in landTime:
            earliestFinishTime = min(
                earliestFinishTime, max(waterFt, landSt) + landDur
            )

        return earliestFinishTime
