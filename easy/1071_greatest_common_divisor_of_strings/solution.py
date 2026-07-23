import math


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        pivot = math.gcd(len(str1), len(str2))

        if str1[:pivot] != str2[:pivot]:
            return ""

        if (
            str1.count(str1[:pivot]) != len(str1) // pivot
            or str2.count(str2[:pivot]) != len(str2) // pivot
        ):
            return ""

        return str1[:pivot]
