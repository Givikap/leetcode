class Solution:
    def validDigit(self, n: int, x: int) -> bool:
        valid = False

        while n:
            if n == x:
                valid = False
                break
            if n % 10 == x:
                valid = True

            n //= 10

        return valid
