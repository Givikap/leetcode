class Solution:
    def totalMoney(self, n: int) -> int:
        money_sum = 0

        for week in range(n // 7 + 1):
            days_in_week = min(n, 7)

            for money in range(1, days_in_week + 1):
                money_sum += money

            money_sum += days_in_week * week

            n -= min(n, 7)

        return money_sum
