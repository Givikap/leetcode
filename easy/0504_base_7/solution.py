from collections import deque


class Solution:
    def convertToBase7(self, num: int) -> str:
        if abs(num) < 7:
            return str(num)

        is_negative = num < 0
        if is_negative:
            num = -num

        dq = deque()

        while num:
            dq.appendleft(chr(48 + num % 7))
            num //= 7

        if is_negative:
            dq.appendleft("-")

        return "".join(dq)
