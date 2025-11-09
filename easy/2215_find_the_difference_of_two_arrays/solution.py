from typing import List


class Solution:
    def findDifference(
        self, nums1: List[int], nums2: List[int]
    ) -> List[List[int]]:
        nums1_set = set(nums1)
        nums2_set = set(nums2)

        return [
            [num for num in nums1_set if num not in set(nums2_set)],
            [num for num in nums2_set if num not in set(nums1_set)],
        ]
