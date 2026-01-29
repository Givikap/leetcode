from collections import Counter
from typing import List


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        uncommon_words = []

        s1_counter = Counter(s1.split())
        s2_counter = Counter(s2.split())

        for word, count in s1_counter.items():
            if count == 1 and word not in s2_counter:
                uncommon_words.append(word)

        for word, count in s2_counter.items():
            if count == 1 and word not in s1_counter:
                uncommon_words.append(word)

        return uncommon_words
