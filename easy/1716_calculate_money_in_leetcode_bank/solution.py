class Solution:
    def totalMoney(self, n: int) -> int:
        return sum(
            7 * week + 28 for week in range(n // 7)
        ) + sum(
            day + n // 7 for day in range(1, n % 7 + 1)
        )
