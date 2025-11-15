from collections import Counter


class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        return int(min(Counter(str(n)).items(), key=lambda t: (t[1], t[0]))[0])
