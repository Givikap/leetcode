from typing import List


class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        bitwise_array = []

        for i in range(len(nums)):
            for j in range(nums[i]):
                if j | (j + 1) == nums[i]:
                    bitwise_array[i] = j
                    break

                j += 1
            else:
                bitwise_array[i] = -1

        return bitwise_array
