from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        cumilative_xor = 0

        for i in range(len(nums) + 1):
            cumilative_xor ^= i

        for num in nums:
            cumilative_xor ^= num

        return cumilative_xor
