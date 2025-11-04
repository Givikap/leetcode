import heapq
import math
from collections import Counter
from typing import List


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        x_sums = [0] * (len(nums) - k + 1)

        for i in range(len(nums) - k + 1):
            heap = [
                (-count, -num)
                for num, count in Counter(nums[i : k + i]).items()
            ]
            heapq.heapify(heap)

            x_sums[i] = sum(
                math.prod(heapq.heappop(heap))
                for _ in range(min(x, len(heap)))
            )

        return x_sums
