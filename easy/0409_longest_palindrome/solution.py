from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter = Counter(s)

        return sum([count - (count % 2 == 1) for count in counter.values()]) + any(
            count % 2 == 1 for count in counter.values()
        )
