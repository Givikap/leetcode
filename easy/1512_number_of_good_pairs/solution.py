from collections import Counter
from typing import List


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        return sum(
            count * (count - 1) // 2 for count in Counter(nums).values()
        )
