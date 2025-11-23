from collections import Counter
from typing import List


class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        for s, count in Counter(arr).items():
            if count == 1:
                k -= 1

                if k == 0:
                    return s

        return ""
