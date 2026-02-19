from typing import List


class Solution:
    def check(self, nums: List[int]) -> bool:
        nums_len = len(nums)

        i = 1

        while i < nums_len:
            if nums[i - 1] > nums[i]:
                break

            i += 1
        else:
            return True

        while i < nums_len - 1:
            if nums[i] > nums[i + 1]:
                return False

            i += 1

        return nums[0] >= nums[-1]
