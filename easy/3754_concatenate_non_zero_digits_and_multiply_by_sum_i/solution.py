class Solution:
    def sumAndMultiply(self, n: int) -> int:
        digits = []

        while n:
            digit = n % 10

            if digit != 0:
                digits.append(digit)

            n //= 10

        digitsSum = sum(digits)

        while digits:
            n = n * 10 + digits.pop()

        return n * digitsSum
