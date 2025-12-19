from typing import List


class Solution:
    def findMedianSortedArrays(
        self, nums1: List[int], nums2: List[int]
    ) -> float:
        nums1_len = len(nums1)
        nums2_len = len(nums2)
        nums_len = nums1_len + nums2_len

        i1 = i2 = 0
        curr = None

        for _ in range(nums_len // 2 + 1):
            prev = curr

            if i2 == nums2_len or (i1 != nums1_len and nums1[i1] < nums2[i2]):
                curr = nums1[i1]
                i1 += 1
            else:
                curr = nums2[i2]
                i2 += 1

        if nums_len % 2 == 0:
            return (prev + curr) / 2
        else:
            return curr
