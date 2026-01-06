from collections import Counter
from typing import List


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_counter = Counter(chars)
        chars_count = 0

        for word in words:
            word_counter = Counter(word)

            for c, count in word_counter.items():
                if c not in chars_counter or chars_counter[c] < count:
                    break
            else:
                chars_count += len(word)

        return chars_count
