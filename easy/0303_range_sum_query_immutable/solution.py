from typing import List

class NumArray:
    def __init__(self, nums: List[int]):
        self.range = tuple(nums)
        self.sumRanges = {}

    def sumRange(self, left: int, right: int) -> int:
        key = (left, right)

        if key not in self.sumRanges:
            self.sumRanges[key] = sum(self.range[left:right+1])

        return self.sumRanges.get(key)