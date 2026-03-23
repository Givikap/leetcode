from collections import Counter
from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        return not any(
            count != 1 for count in Counter(Counter(arr).values()).values()
        )
