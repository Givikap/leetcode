from collections import Counter


class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels_set = set("aeiou")

        max_vowel_count = 0
        max_consonant_count = 0

        for c, count in Counter(s).items():
            if c in vowels_set:
                if max_vowel_count < count:
                    max_vowel_count = count
            else:
                if max_consonant_count < count:
                    max_consonant_count = count

        return max_vowel_count + max_consonant_count
