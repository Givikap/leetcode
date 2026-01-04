from collections import Counter


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        text_counter = Counter(text)

        return min(
            text_counter.get("b", 0),
            text_counter.get("a", 0),
            text_counter.get("l", 0) // 2,
            text_counter.get("o", 0) // 2,
            text_counter.get("n", 0),
        )
