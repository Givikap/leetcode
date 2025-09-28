class Solution:
    def trailingZeroes(self, n: int) -> int:
        trailing_zeroes = 0

        while n > 0:
            n //= 5
            trailing_zeroes += n

        return trailing_zeroes
