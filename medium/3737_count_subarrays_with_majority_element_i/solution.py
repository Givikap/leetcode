from typing import List


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)

        prefixCounts = [0] * (len(nums) + 1)

        for i in range(1, n + 1):
            prefixCounts[i] = prefixCounts[i - 1] + (nums[i - 1] == target)

        count = 0

        for i in range(n):
            for j in range(i, n):
                if 2 * (prefixCounts[j + 1] - prefixCounts[i]) > j - i + 1:
                    count += 1

        return count
