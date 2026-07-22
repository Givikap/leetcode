from typing import List


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        substrings = set()

        for i in range(len(words)):
            for j in range(len(words)):
                if i == j:
                    continue

                if words[j] in words[i]:
                    substrings.add(words[j])

        return list(substrings)
