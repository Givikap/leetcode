from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_sum = len(nums) * (len(nums) + 1) // 2

        for num in nums:
            nums_sum -= num

        return nums_sum