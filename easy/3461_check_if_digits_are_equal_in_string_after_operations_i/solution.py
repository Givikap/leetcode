class Solution:
    def hasSameDigits(self, s: str) -> bool:
        digits = [int(c) for c in s]

        while len(digits) > 2:
            digits = [(d1 + d2) % 10 for d1, d2 in zip(digits, digits[1:])]

        return digits[0] == digits[1]
