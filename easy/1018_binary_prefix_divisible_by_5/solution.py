from typing import List


class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        nums_str = "".join(map(str, nums))
        return [
            int(nums_str[:end], 2) % 5 == 0 for end in range(1, len(nums) + 1)
        ]
