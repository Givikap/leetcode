from typing import List


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort()

        widestGap = 0

        for i in range(len(points) - 1):
            widestGap = max(widestGap, points[i + 1][0] - points[i][0])

        return widestGap
