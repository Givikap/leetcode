import heapq
import math
from typing import List


class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        return math.prod(heapq.nlargest(2, nums)) - math.prod(
            heapq.nsmallest(2, nums)
        )
