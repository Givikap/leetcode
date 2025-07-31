from itertools import combinations
from functools import reduce
from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        xorSum = sum(nums)

        for l in range(2, len(nums) + 1):
            xorSum += sum([
                reduce(lambda x, y: x ^ y, subset)
                for subset in combinations(nums, l)
            ])

        return xorSum     