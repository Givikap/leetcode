from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        cumilative_xor = 0

        for i, num in enumerate(nums):
            cumilative_xor ^= i ^ num 

        return cumilative_xor ^ len(nums)
