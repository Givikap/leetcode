class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        frequencies = [0] * 10

        while n:
            frequencies[n % 10] += 1
            n //= 10

        score = 0

        for digit, frequency in enumerate(frequencies):
            score += digit * frequency

        return score
