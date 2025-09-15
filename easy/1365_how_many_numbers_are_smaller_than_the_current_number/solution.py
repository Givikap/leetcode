from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        num_to_rank = {}

        for i, num in enumerate(sorted(nums)):
            num_to_rank.setdefault(num, i)

        return [num_to_rank[num] for num in nums]
