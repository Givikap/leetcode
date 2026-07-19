from typing import List


class Solution:
    def canReach(self, start: List[int], target: List[int]) -> bool:
        return abs(target[0] - start[0]) % 2 == abs(target[1] - start[1]) % 2
