from typing import List


class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        letters = [0] * len(words)

        for i, word in enumerate(words):
            for c in word:
                letters[i] += weights[ord(c) - 97]

            letters[i] = chr(122 - (letters[i] % 26))

        return "".join(letters)
