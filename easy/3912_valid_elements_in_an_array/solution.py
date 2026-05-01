from typing import List


class Solution:
    def findValidElements(self, nums: List[int]) -> List[int]:
        prefix_maxes = [0] * len(nums)
        suffix_maxes = [0] * len(nums)

        for i in range(1, len(nums)):
            prefix_maxes[i] = max(prefix_maxes[i - 1], nums[i - 1])
        for i in range(len(nums) - 2, -1, -1):
            suffix_maxes[i] = max(suffix_maxes[i + 1], nums[i + 1])

        valid_nums = [nums[0]]

        for i in range(1, len(nums) - 1):
            if nums[i] > prefix_maxes[i] or nums[i] > suffix_maxes[i]:
                valid_nums.append(nums[i])

        if len(nums) != 1:
            valid_nums.append(nums[-1])

        return valid_nums
