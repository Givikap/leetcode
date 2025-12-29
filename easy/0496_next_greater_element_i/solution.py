from typing import List


class Solution:
    def nextGreaterElement(
        self, nums1: List[int], nums2: List[int]
    ) -> List[int]:
        nums2_indices_map = {num: i for i, num in enumerate(nums2)}

        greater_elements = []

        for num in nums1:
            if num in nums2_indices_map:
                for i in range(nums2_indices_map[num], len(nums2)):
                    if nums2[i] > num:
                        greater_elements.append(nums2[i])
                        break
                else:
                    greater_elements.append(-1)

        return greater_elements
