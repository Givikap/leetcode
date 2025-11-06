from collections import Counter
from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1_counter = Counter(nums1)
        nums2_counter = Counter(nums2)

        intersection = []

        for num in nums1_counter.keys() & nums2_counter.keys():
            intersection.extend(
                [num] * min(nums1_counter[num], nums2_counter[num])
            )

        return intersection
