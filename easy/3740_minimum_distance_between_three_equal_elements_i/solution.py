from collections import defaultdict
from itertools import combinations
from typing import List


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        indices_map = defaultdict(list)

        for i, num in enumerate(nums):
            indices_map[num].append(i)

        min_dist = float("inf")

        for indices in indices_map.values():
            if len(indices) >= 3:
                for triple in combinations(indices, 3):
                    min_dist = min(
                        min_dist,
                        abs(triple[0] - triple[1])
                        + abs(triple[1] - triple[2])
                        + abs(triple[2] - triple[0]),
                    )

        return min_dist if min_dist != float("inf") else -1
