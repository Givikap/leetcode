from collections import Counter
from typing import List


class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        return [num for num, count in Counter(nums).items() if count == 2]
