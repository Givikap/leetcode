class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels_set = set("aeiouAEIOU")

        vowels_indices = [i for i, c in enumerate(s) if c in vowels_set]

        return "".join(
            [
                s[vowels_indices.pop()] if s[i] in vowels_set else c
                for i, c in enumerate(s)
            ]
        )
