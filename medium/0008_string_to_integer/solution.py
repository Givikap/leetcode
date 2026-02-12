class Solution:
    def myAtoi(self, s: str) -> int:
        s_len = len(s)

        i = 0
        while i < s_len and s[i] == " ":
            i += 1

        sign = 1
        if i < s_len and (s[i] == "+" or s[i] == "-"):
            sign = -1 if s[i] == "-" else 1
            i += 1

        num = 0

        while i < s_len and s[i].isdigit():
            num = num * 10 + (ord(s[i]) - 48)

            if sign == 1 and num > 2147483647:
                return 2147483647
            if sign == -1 and -num < -2147483648:
                return -2147483648

            i += 1

        return sign * num
