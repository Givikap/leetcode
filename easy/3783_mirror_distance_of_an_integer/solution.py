class Solution:
    def mirrorDistance(self, n: int) -> int:
        n_copy = n
        reversed_n = 0

        while n_copy:
            reversed_n = reversed_n * 10 + n_copy % 10
            n_copy //= 10

        return abs(n - reversed_n)
