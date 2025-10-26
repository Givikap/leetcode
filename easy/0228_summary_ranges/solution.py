from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []

        ranges = []

        start = nums[0]

        for i in range(len(nums) - 1):
            if nums[i] + 1 != nums[i + 1]:
                if start == nums[i]:
                    ranges.append(str(start))
                else:
                    ranges.append(f"{start}->{nums[i]}")

                start = nums[i + 1]

        if start == nums[-1]:
            ranges.append(str(start))
        else:
            ranges.append(f"{start}->{nums[-1]}")

        return ranges
