from typing import List


class Solution:
    def minAbsoluteDifference(self, nums: List[int]) -> int:
        min_difference = len(nums) + 1

        for i in range(len(nums)):
            if nums[i] == 0:
                continue
            elif nums[i] == 1:
                other = 2
            else:
                other = 1

            for j in range(i + 1, len(nums)):
                if nums[j] == other:
                    min_difference = min(min_difference, abs(i - j))

        return min_difference if min_difference != len(nums) + 1 else -1
