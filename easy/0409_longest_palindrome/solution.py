from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        max_length = 0
        has_odd = 0

        for count in Counter(s).values():
            if count % 2 == 0:
                max_length += count
            else:
                max_length += count - 1
                has_odd = 1

        return max_length + has_odd
