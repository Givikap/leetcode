from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        uniqueCount = 1
        curr = 1
        
        for i in range(1, len(nums)):
            if nums[i-1] != nums[i]:
                nums[curr] = nums[i]

                curr += 1
                uniqueCount += 1

        return uniqueCount