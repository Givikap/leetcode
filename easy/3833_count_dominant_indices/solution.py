from typing import List


class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        postfix_sums = [0] * len(nums)

        for i in range(len(nums) - 2, -1, -1):
            postfix_sums[i] = postfix_sums[i + 1] + nums[i + 1]

        count = 0

        for i in range(len(nums) - 1):
            if nums[i] > postfix_sums[i] / (len(nums) - i - 1):
                count += 1

        return count
