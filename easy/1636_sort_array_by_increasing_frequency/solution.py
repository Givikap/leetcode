from collections import Counter
from typing import List


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        sorted_nums = []

        for num, count in sorted(
            Counter(nums).items(), key=lambda t: (t[1], -t[0])
        ):
            sorted_nums.extend([num] * count)

        return sorted_nums
