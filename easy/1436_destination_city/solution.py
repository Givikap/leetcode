from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        paths_map = dict(paths)

        for destination in paths_map.values():
            if destination not in paths_map:
                return destination

        return ""
