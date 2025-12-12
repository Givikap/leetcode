from typing import List


class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        a, b = 1, n - 1

        while "0" in str(a) + str(b):
            a += 1
            b -= 1

        return [a, b]
