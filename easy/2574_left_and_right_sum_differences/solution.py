from typing import List


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)

        differences = []

        numsSum = sum(nums)
        leftSum = 0

        for i in range(n):
            rightSum = numsSum - leftSum - nums[i]
            differences.append(abs(leftSum - rightSum))
            leftSum += nums[i]

        return differences
