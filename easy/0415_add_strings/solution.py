class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = [""] * max(len(num1), len(num2))
        carry = 0

        num1 = num1.zfill(len(result))
        num2 = num2.zfill(len(result))

        for i in range(len(result) - 1, -1, -1):
            digit = int(num1[i]) + int(num2[i]) + carry

            result[i] = str(digit % 10)
            carry = digit // 10

        if carry:
            result = ["1"] + result

        return "".join(result)
