import math
from typing import List


class Solution:
    def gcdSum(self, nums: List[int]) -> int:
        n = len(nums)

        mx = [nums[0]] * n
        prefixGcd = [0] * n

        for i in range(1, n):
            mx[i] = max(mx[i - 1], nums[i])

        for i in range(n):
            prefixGcd[i] = math.gcd(nums[i], mx[i])

        prefixGcd.sort()

        gcdSum = 0

        for i in range(n // 2):
            gcdSum += math.gcd(prefixGcd[i], prefixGcd[n - i - 1])

        return gcdSum
