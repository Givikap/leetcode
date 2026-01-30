from collections import Counter
from typing import List


class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        for num, count in Counter(nums).items():
            if count * 2 == len(nums):
                return num

        return -1
