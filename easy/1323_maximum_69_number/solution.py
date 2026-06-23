class Solution:
    def maximum69Number(self, num: int) -> int:
        digits = []

        while num:
            digits.append(num % 10)
            num //= 10

        numChanged = False

        while digits:
            digit = digits.pop()

            if not numChanged and digit == 6:
                numChanged = True
                digit = 9

            num = num * 10 + digit

        return num
