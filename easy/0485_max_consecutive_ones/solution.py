from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ones_count = 0
        max_ones_count = 0

        for num in nums:
            if num:
                ones_count += 1

                if ones_count > max_ones_count:
                    max_ones_count = ones_count
            else:
                ones_count = 0

        return max_ones_count
