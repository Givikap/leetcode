class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        key = 0

        for div in (1000, 100, 10, 1):
            key = key * 10 + min(num1 // div, num2 // div, num3 // div)

            num1 %= div
            num2 %= div
            num3 %= div

        return key
