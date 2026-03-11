from typing import List


class Solution:
    def minimumIndex(self, capacity: List[int], itemSize: int) -> int:
        min_i = 0

        for i in range(len(capacity)):
            if capacity[i] >= itemSize and (
                capacity[min_i] < itemSize or capacity[i] < capacity[min_i]
            ):
                min_i = i

        return min_i if capacity[min_i] >= itemSize else -1
