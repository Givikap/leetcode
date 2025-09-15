from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ranked_nums = [[num, i] for i, num in enumerate(sorted(nums))]

        for i in range(len(ranked_nums) - 1):
            if ranked_nums[i][0] == ranked_nums[i + 1][0]:
                ranked_nums[i + 1][1] = ranked_nums[i][1]

        num_to_smaller_count = dict(ranked_nums)

        return [num_to_smaller_count[num] for num in nums]
