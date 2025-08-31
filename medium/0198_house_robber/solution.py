from functools import lru_cache
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache(None)
        def rob_from(i):
            if i >= len(nums):
                return 0

            return max(rob_from(i+1), nums[i] + rob_from(i+2))
            
        return rob_from(0)
