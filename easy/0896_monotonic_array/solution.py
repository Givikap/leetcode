from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True

        increasing = False
        decreasing = False

        for i in range(1, len(nums)):
            if (increasing and nums[i] < nums[i - 1]) or (
                decreasing and nums[i] > nums[i - 1]
            ):
                return False
            elif nums[i] > nums[i - 1]:
                increasing = True
            elif nums[i] < nums[i - 1]:
                decreasing = True

        return True
