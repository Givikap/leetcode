from typing import List


class Solution:
    def mergeSimilarItems(
        self, items1: List[List[int]], items2: List[List[int]]
    ) -> List[List[int]]:
        items_map = {}

        for value, weight in [*items1, *items2]:
            items_map[value] = items_map.get(value, 0) + weight

        return sorted(map(list, items_map.items()))
