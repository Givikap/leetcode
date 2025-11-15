from typing import List


class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        start = min(nums)
        end = max(nums)

        nums_set = set(range(start, end + 1))

        for num in nums:
            if num in nums_set:
                nums_set.remove(num)

        return sorted(nums_set)
