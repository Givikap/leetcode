class Solution:
    def checkGoodInteger(self, n: int) -> bool:
        digitSum = 0
        squareSum = 1

        while n:
            digit = n % 10
            n //= 10

            digitSum += digit
            squareSum += digit * digit

        return squareSum - digitSum >= 50
