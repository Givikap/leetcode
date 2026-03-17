from collections import Counter
from typing import List


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1_counter = Counter(arr1)

        sorted_arr = []

        for num in arr2:
            sorted_arr.extend([num] * arr1_counter[num])
            arr1_counter.pop(num)

        for num, count in sorted(arr1_counter.items()):
            sorted_arr.extend([num] * count)

        return sorted_arr
