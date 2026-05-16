from collections import defaultdict
from typing import List


class Solution:
    def isGood(self, nums: List[int]) -> bool:
        max_num = 0
        nums_counter = defaultdict(int)

        for num in nums:
            max_num = max(max_num, num)
            nums_counter[num] += 1

        for num in range(1, max_num):
            if nums_counter[num] != 1:
                return False

        return nums_counter[max_num] == 2
