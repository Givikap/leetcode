from typing import List


class Solution:
    def countOppositeParity(self, nums: List[int]) -> List[int]:
        parities = [0] * len(nums)

        even = 0
        odd = 0

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] % 2 == 0:
                parities[i] = odd
                even += 1
            else:
                parities[i] = even
                odd += 1

        return parities
