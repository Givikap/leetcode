from typing import List


class Solution:
    def limitOccurrences(self, nums: List[int], k: int) -> List[int]:
        limitedNums = [nums[0]]

        i = 1
        count = 1
        curr = nums[0]

        while i < len(nums):
            if nums[i] != curr:
                curr = nums[i]
                count = 1
            elif count == k:
                i += 1
                continue
            else:
                count += 1

            limitedNums.append(curr)
            i += 1

        return limitedNums
