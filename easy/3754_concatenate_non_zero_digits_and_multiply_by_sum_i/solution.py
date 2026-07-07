class Solution:
    def sumAndMultiply(self, n: int) -> int:
        nNew = 0
        mul = 1
        digitsSum = 0

        while n:
            digit = n % 10
            n //= 10

            if digit != 0:
                nNew = digit * mul + nNew
                mul *= 10
                digitsSum += digit

        return nNew * digitsSum
