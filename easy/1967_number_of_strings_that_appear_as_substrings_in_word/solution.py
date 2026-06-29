from typing import List


class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        stringsCount = 0

        for pattern in patterns:
            if pattern in word:
                stringsCount += 1

        return stringsCount
