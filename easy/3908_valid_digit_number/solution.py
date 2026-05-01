class Solution:
    def validDigit(self, n: int, x: int) -> bool:
        valid = False

        while n > 9:
            if n % 10 == x:
                valid = True

            n //= 10

        if n == x:
            return False

        return valid
