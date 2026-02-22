from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)

        prefix_sums = [1, nums[0]]
        postfix_sums = [nums[-1]] * (nums_len - 1) + [1]

        for i in range(1, nums_len - 1):
            prefix_sums.append(prefix_sums[i] * nums[i])

        for i in range(nums_len - 2, 0, -1):
            postfix_sums[i - 1] = postfix_sums[i] * nums[i]

        return [prefix_sums[i] * postfix_sums[i] for i in range(nums_len)]
