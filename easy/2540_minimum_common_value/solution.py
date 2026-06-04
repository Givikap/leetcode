from typing import List


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        nums_set = set(nums1).intersection(set(nums2))
        return min(nums_set) if nums_set else -1
