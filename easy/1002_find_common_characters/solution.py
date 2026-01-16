from collections import Counter
from typing import List


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        word_counters = [Counter(word) for word in words]
        common_chars = []

        for c in set("".join(words)):
            for word_counter in word_counters:
                if c not in word_counter:
                    break
            else:
                for _ in range(
                    min(word_counter[c] for word_counter in word_counters)
                ):
                    common_chars.append(c)

        return common_chars
