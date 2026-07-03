from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        currSum = sum(nums[i] for i in range(k))
        maxAverage = currSum / k

        for i in range(1, len(nums) - k + 1):
            currSum = currSum - nums[i - 1] + nums[i + k - 1]
            maxAverage = max(maxAverage, currSum / k)

        return maxAverage
