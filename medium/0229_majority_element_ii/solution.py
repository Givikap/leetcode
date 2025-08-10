from collections import Counter
from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        target = len(nums) / 3
        return [num for num, count in Counter(nums).items() if count > target]