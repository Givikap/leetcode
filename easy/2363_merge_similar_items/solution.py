from collections import Counter
from typing import List


class Solution:
    def mergeSimilarItems(
        self, items1: List[List[int]], items2: List[List[int]]
    ) -> List[List[int]]:
        items_map = Counter()

        for value, weight in items1:
            items_map[value] += weight
        for value, weight in items2:
            items_map[value] += weight

        return sorted([value, weight] for value, weight in items_map.items())
