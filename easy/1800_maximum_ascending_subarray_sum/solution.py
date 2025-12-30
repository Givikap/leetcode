from typing import List


class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        curr_ascending_sum = max_ascending_sum = 0

        prev = 0

        for num in nums:
            if prev < num:
                curr_ascending_sum += num
            else:
                max_ascending_sum = max(curr_ascending_sum, max_ascending_sum)
                curr_ascending_sum = num

            prev = num

        return max(curr_ascending_sum, max_ascending_sum)
