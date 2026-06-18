import math


class Solution:
    def countMonobit(self, n: int) -> int:
        return math.floor(math.log2(n + 1) + 1)
