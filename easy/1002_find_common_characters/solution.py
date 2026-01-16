from collections import Counter
from typing import List


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        word_counters = [Counter(word) for word in words]
        common_chars = []

        for c in set("".join(words)):
            min_count = 101

            for word_counter in word_counters:
                min_count = min(min_count, word_counter[c])

                if min_count == 0:
                    break
            else:
                common_chars.extend([c] * min_count)

        return common_chars
