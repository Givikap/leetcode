from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targets_map = {}

        for i in range(len(nums)):
            other_num = target - nums[i]

            if other_num in targets_map:
                return [targets_map[other_num], i]
            else:
                targets_map[nums[i]] = i
