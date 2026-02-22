from typing import List


class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        modified = False

        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                if modified or (
                    (nums[i - 1] if i != 0 else nums[i + 1]) > nums[i + 1]
                    and nums[i]
                    > (nums[i + 2] if i + 2 < len(nums) else nums[i])
                ):
                    return False
                else:
                    modified = True

        return True
