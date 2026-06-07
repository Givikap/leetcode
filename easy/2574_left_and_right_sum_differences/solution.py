from typing import List


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)

        leftSums = [0] * n
        rightSums = [0] * n

        for i in range(1, n):
            leftSums[i] = leftSums[i - 1] + nums[i - 1]

        for i in range(n - 2, -1, -1):
            rightSums[i] = rightSums[i + 1] + nums[i + 1]

        return [abs(leftSums[i] - rightSums[i]) for i in range(n)]
