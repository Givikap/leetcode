from collections import Counter


class Solution:
    def canConstruct(self, ransom_note: str, magazine: str) -> bool:
        magazine_counter = Counter(magazine)

        for c in ransom_note:
            if c in magazine_counter and magazine_counter[c] > 0:
                magazine_counter[c] -= 1
            else:
                return False

        return True
