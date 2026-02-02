from collections import Counter
from typing import List


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words_counter = Counter(
            (
                paragraph.replace("!", " ")
                .replace("?", " ")
                .replace("'", " ")
                .replace(",", " ")
                .replace(";", " ")
                .replace(".", " ")
                .lower()
                .split()
            )
        )

        for word in banned:
            if word in words_counter:
                words_counter[word] = 0

        return max((count, word) for word, count in words_counter.items())[1]
