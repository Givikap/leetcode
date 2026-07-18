import math
from typing import List


class Solution:
    def findGCD(self, nums: List[int]) -> int:
        minNum = nums[0]
        maxNum = nums[0]

        for i in range(1, len(nums)):
            minNum = min(minNum, nums[i])
            maxNum = max(maxNum, nums[i])

        return math.gcd(minNum, maxNum)
