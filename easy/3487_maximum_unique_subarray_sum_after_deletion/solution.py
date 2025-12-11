from typing import List


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        unique_positive_nums = [num for num in set(nums) if num > 0]

        if len(unique_positive_nums) == 0:
            return max(nums)

        return sum(unique_positive_nums)
