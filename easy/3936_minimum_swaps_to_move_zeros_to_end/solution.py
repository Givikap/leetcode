from typing import List


class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        swaps = 0

        while True:
            while left < right and nums[left] != 0:
                left += 1

            while left < right and nums[right] == 0:
                right -= 1

            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
                swaps += 1
            else:
                break

        return swaps
