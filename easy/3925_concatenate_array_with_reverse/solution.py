from typing import List


class Solution:
    def concatWithReverse(self, nums: List[int]) -> List[int]:
        for i in range(len(nums) - 1, -1, -1):
            nums.append(nums[i])

        return nums
