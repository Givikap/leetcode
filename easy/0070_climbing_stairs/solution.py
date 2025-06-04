class Solution:
    def climbStairs(self, n: int) -> int:
        phi = (1 + 5 ** 0.5) / 2
        psi = (1 - 5 ** 0.5) / 2

        return int((phi ** (n + 1) - psi ** (n + 1)) / (phi - psi))