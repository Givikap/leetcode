from collections import Counter
from typing import List


class Solution:
    def findLucky(self, nums: List[int]) -> int:
        return max(
            [num for num, count in Counter(nums).items() if num == count],
            default=-1,
        )
