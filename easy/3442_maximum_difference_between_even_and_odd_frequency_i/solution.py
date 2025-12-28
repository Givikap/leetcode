from collections import Counter


class Solution:
    def maxDifference(self, s: str) -> int:
        s_counter = Counter(s)

        max_odd_frequency = -1
        min_even_frequency = 101

        for frequency in s_counter.values():
            if frequency % 2 == 1 and frequency > max_odd_frequency:
                max_odd_frequency = frequency
            elif frequency % 2 == 0 and frequency < min_even_frequency:
                min_even_frequency = frequency

        return max_odd_frequency - min_even_frequency
