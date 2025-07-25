from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        numsSquared = [0] * len(nums)
        left, right = 0, len(nums) - 1
        i = right

        while left <= right:
            if abs(nums[left]) > abs(nums[right]):
                numsSquared[i] = nums[left] ** 2
                left += 1
            else:
                numsSquared[i] = nums[right] ** 2
                right -= 1
            
            i -= 1

        return numsSquared