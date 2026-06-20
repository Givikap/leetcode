from collections import Counter
from typing import List


class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        reversedNums = list(reversed(nums))

        numsCounter = Counter(nums)

        maxCount = max(numsCounter.values())
        minLen = len(nums)

        for num, count in numsCounter.items():
            if count == maxCount:
                left = nums.index(num)
                right = len(nums) - reversedNums.index(num) - 1

                minLen = min(minLen, right - left + 1)

        return minLen
