from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counter_map = {}

        for num in nums:
            counter_map[num] = counter_map.get(num, 0) + 1

        return max(counter_map, key=counter_map.get)
