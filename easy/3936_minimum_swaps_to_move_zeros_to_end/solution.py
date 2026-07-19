from typing import List


class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        return nums[: -nums.count(0)].count(0)
