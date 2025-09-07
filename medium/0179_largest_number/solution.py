from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        result = "".join(
            sorted(map(str, nums), key=lambda num: num * 10, reverse=True)
        )

        return "0" if result[0] == "0" else result
