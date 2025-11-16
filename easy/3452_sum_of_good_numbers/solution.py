from typing import List


class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        return sum(
            num
            for i, num in enumerate(nums)
            if not (
                (i - k >= 0 and nums[i - k] >= num)
                or (i + k < len(nums) and nums[i + k] >= num)
            )
        )
