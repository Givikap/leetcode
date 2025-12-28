from collections import Counter


class Solution:
    def maxDifference(self, s: str) -> int:
        max_odd_frequency = 0
        min_even_frequency = 101

        for frequency in Counter(s).values():
            if frequency % 2:
                max_odd_frequency = max(frequency, max_odd_frequency)
            else:
                min_even_frequency = min(frequency, min_even_frequency)

        return max_odd_frequency - min_even_frequency
