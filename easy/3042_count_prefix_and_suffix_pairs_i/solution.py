from typing import List


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        return len([
            1
            for i in range(len(words) - 1)
            for j in range(i+1, len(words))
            if words[j].startswith(words[i]) and words[j].endswith(words[i])
        ])
