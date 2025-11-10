from typing import List


class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return len(heights) - sum(
            height == expected
            for height, expected in zip(heights, sorted(heights))
        )
