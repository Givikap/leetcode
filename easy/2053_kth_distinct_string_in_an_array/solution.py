from collections import defaultdict
from typing import List


class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        ch_counter = defaultdict(int)
        distinct = []

        for ch in arr:
            if ch not in ch_counter:
                distinct.append(ch)

            ch_counter[ch] += 1

        for ch, count in ch_counter.items():
            if count == 1:
                k -= 1

            if k == 0:
                return ch

        return ""
