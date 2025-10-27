class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            newNum = 0

            while num:
                newNum += num % 10
                num //= 10

            num = newNum

        return num
