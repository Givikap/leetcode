from typing import List


class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)
        return [nums[(i + num) % nums_len] for i, num in enumerate(nums)]
