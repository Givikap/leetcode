class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        new_word = []

        for i in range(min(len(word1), len(word2))):
            new_word.extend((word1[i], word2[i]))

        longer_word = word1 if len(word1) > len(word2) else word2
        return "".join(new_word) + longer_word[min(len(word1), len(word2)) :]
