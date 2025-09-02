from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        max_length = 0

        counter = Counter(s)

        for c, count in counter.items():
            if count % 2 == 0:
                max_length += counter[c]
            else:
                max_length += counter[c] - 1

        return max_length + any(count % 2 == 1 for count in counter.values())
