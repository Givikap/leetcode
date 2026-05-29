import math


class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num < 2:
            return False

        divisors_sum = 0

        for i in range(1, int(math.sqrt(num)) + 1):
            if num % i == 0:
                divisors_sum += i + num // i

        return divisors_sum - num == num
