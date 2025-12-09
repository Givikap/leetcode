class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        if not word.isalnum():
            return False

        vowels_set = set("aeiouAEIOU")

        contains_vowel = False
        contains_consonant = False

        for c in word:
            if not contains_vowel and c in vowels_set:
                contains_vowel = True
            if c not in vowels_set and not c.isdigit():
                contains_consonant = True

            if contains_vowel and contains_consonant:
                return True

        return False
