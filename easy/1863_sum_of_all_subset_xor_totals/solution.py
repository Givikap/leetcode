from functools import reduce
from typing import List


class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x | y, nums) * (2 ** (len(nums) - 1))
