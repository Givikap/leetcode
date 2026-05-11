from typing import List


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        digits = []

        for num in nums:
            stack = []

            while num:
                stack.append(num % 10)
                num //= 10

            while stack:
                digits.append(stack.pop())

        return digits
