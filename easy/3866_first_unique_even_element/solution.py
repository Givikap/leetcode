from collections import Counter
from typing import List


class Solution:
    def firstUniqueEven(self, nums: List[int]) -> int:
        for num, count in Counter(nums).items():
            if count == 1 and num % 2 == 0:
                return num

        return -1
