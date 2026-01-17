from collections import Counter
from typing import List


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        words_len = len(words)

        for count in Counter("".join(words)).values():
            if count % words_len != 0:
                return False

        return True
