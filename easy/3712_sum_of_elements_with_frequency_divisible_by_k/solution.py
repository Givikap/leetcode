from collections import Counter
from typing import List


class Solution:
    def sumDivisibleByK(self, nums: List[int], k: int) -> int:
        return sum(
            num * count
            for num, count in Counter(nums).items()
            if count % k == 0
        )
