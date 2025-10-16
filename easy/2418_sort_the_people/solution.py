from typing import List


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [
            name
            for _, name in sorted(
                (-height, names[i]) for i, height in enumerate(heights)
            )
        ]
