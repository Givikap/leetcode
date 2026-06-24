from typing import List


class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rankMap = {num: i + 1 for i, num in enumerate(sorted(set(arr)))}
        return [rankMap[num] for num in arr]
