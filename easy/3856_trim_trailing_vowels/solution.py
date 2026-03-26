class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        vowels_set = set("aeiou")

        i = len(s) - 1
        while i != -1 and s[i] in vowels_set:
            i -= 1

        return s[: i + 1]
