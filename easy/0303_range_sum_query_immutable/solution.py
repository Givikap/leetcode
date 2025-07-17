from typing import List

class NumArray:
    def __init__(self, nums: List[int]):
        self.range = nums

    def sumRange(self, left: int, right: int) -> int:
        return sum(self.range[left:right+1])