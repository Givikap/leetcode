class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        if n == 0:
            return 1
        if n == 1:
            return x

        result = self.myPow(x, abs(n) // 2)
        result *= result

        if n % 2 == 1:
            result *= x

        if n < 0:
            result = 1 / result

        return result
