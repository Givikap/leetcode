class Solution:
    def sumOfGoodIntegers(self, n: int, k: int) -> int:
        return sum(
            x for x in range(1, n + k + 1) if abs(n - x) <= k and n & x == 0
        )
