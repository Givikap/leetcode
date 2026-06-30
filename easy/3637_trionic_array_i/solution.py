from typing import List


class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        numsLen = len(nums)

        p = 0
        while p < numsLen - 1 and nums[p] < nums[p + 1]:
            p += 1

        if p == 0 or p == numsLen - 1:
            return False

        q = p
        while q < numsLen - 1 and nums[q] > nums[q + 1]:
            q += 1

        if q == numsLen - 1:
            return False

        while q < numsLen - 1:
            if nums[q] >= nums[q + 1]:
                return False

            q += 1

        return q == numsLen - 1
