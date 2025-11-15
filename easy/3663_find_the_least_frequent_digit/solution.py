from collections import defaultdict


class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        digits_counter = defaultdict(int)

        while n:
            digits_counter[n % 10] += 1
            n //= 10

        return min(digits_counter.items(), key=lambda t: (t[1], t[0]))[0]
