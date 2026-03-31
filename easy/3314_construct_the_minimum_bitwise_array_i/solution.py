from typing import List


class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        bitwise_array = [0] * len(nums)

        for i, num in enumerate(nums):
            if num & 1:
                bitwise_array[i] = num & ~(((num + 1) & ~num) >> 1)
            else:
                bitwise_array[i] = -1

        return bitwise_array
