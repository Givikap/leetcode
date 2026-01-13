from collections import Counter
from typing import List


class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        largest_unique_num = -1

        for num, count in Counter(nums).items():
            if count == 1:
                largest_unique_num = max(num, largest_unique_num)

        return largest_unique_num
