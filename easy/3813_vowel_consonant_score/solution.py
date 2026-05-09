import math


class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        vowels_set = set("aeiou")

        vowels_count = 0
        consonants_count = 0

        for c in s:
            if c in vowels_set:
                vowels_count += 1
            elif c.isalpha():
                consonants_count += 1

        if consonants_count == 0:
            return 0

        return math.floor(vowels_count / consonants_count)
