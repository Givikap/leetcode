from typing import List


class Solution:
    def prefixCount(self, words: List[str], prefix: str) -> int:
        return sum(1 for word in words if word.startswith(prefix))
