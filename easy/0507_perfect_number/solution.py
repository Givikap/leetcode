import math


class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False

        divisors = []

        for i in range(1, int(math.sqrt(num)) + 1):
            if num % i == 0:
                divisors.append(i)
                divisors.append(num // i)

        return sum(divisors) - num == num
