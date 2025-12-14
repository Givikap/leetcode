from functools import reduce
from typing import List


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        nums_product = reduce(lambda x, y: x * y, nums)

        if nums_product > 0:
            return 1
        elif nums_product == 0:
            return 0
        else:
            return -1
