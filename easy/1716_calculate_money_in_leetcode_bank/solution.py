class Solution:
    def totalMoney(self, n: int) -> int:
        weeks, days = divmod(n, 7)
        return (
            weeks * 28
            + 7 * (weeks - 1) * weeks // 2
            + days * (2 * weeks + days + 1) // 2
        )
