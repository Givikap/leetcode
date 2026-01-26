from typing import List


class Solution:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        nums1_len = len(nums1)
        nums2_len = len(nums2)

        i1 = i2 = 0

        nums = []

        while i1 < nums1_len and i2 < nums2_len:
            if nums1[i1][0] < nums2[i2][0]:
                nums.append(nums1[i1])
                i1 += 1
            elif nums1[i1][0] > nums2[i2][0]:
                nums.append(nums2[i2])
                i2 += 1
            else:
                nums.append((nums1[i1][0], nums1[i1][1] + nums2[i2][1]))
                i1 += 1
                i2 += 1

        while i1 < nums1_len:
            nums.append(nums1[i1])
            i1 += 1

        while i2 < nums2_len:
            nums.append(nums2[i2])
            i2 += 1

        return nums
