from collections import Counter
from typing import List


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_counter = Counter(chars)
        chars_count = 0

        for word in words:
            chars_counter_copy = chars_counter.copy()

            for c in word:
                if c not in chars_counter or chars_counter_copy[c] == 0:
                    break

                chars_counter_copy[c] -= 1
            else:
                chars_count += len(word)

        return chars_count
