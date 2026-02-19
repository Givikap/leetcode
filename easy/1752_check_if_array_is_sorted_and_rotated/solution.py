from typing import List


class Solution:
    def check(self, nums: List[int]) -> bool:
        nums_len = len(nums)

        i = 0

        while i < nums_len - 1:
            if nums[i] > nums[i + 1]:
                break

            i += 1

        if i == nums_len - 1:
            return True

        i += 1

        while i < nums_len - 1:
            if nums[i] > nums[i + 1]:
                return False

            i += 1

        return nums[0] >= nums[-1]
