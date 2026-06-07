from typing import List


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        differences = []

        numsSum = sum(nums)
        leftSum = 0

        for num in nums:
            differences.append(abs(leftSum * 2 + num - numsSum))
            leftSum += num

        return differences
