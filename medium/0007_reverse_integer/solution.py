class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2147483647 / 10

        sign = -1 if x < 0 else 1
        x = abs(x)

        reversed_x = 0

        while x:
            if reversed_x > INT_MAX:
                return 0

            reversed_x = reversed_x * 10 + x % 10
            x //= 10

        return sign * reversed_x
