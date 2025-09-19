class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        max_len = max(len(num1), len(num2))

        result = []
        carry = 0

        num1 = num1.zfill(max_len)
        num2 = num2.zfill(max_len)

        for i in range(1, max_len + 1):
            digit = ord(num1[-i]) + ord(num2[-i]) - 96 + carry

            result.append(digit % 10)
            carry = digit // 10

        if carry:
            result.append(1)

        return "".join(map(str, result[::-1]))
