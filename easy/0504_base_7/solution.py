class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"

        is_negative = num < 0
        if is_negative:
            num = -num

        stack = []

        while num:
            stack.append(chr(48 + num % 7))
            num //= 7

        base_7_num = []
        if is_negative:
            base_7_num.append("-")

        while stack:
            base_7_num.append(stack.pop())

        return "".join(base_7_num)
