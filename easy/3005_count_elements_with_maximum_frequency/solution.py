from collections import Counter
from typing import List


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        nums_counter = Counter(nums)
        max_frequency = max(nums_counter.values())
        return max_frequency * sum(
            1
            for frequency in nums_counter.values()
            if frequency == max_frequency
        )
