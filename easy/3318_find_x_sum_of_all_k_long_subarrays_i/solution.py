import heapq
from collections import Counter
from typing import List


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        x_sums = [0] * (len(nums) - k + 1)

        window_counter = Counter(nums[:k])

        for i in range(len(nums) - k + 1):
            heap = [(-count, -num) for num, count in window_counter.items()]
            heapq.heapify(heap)

            for _ in range(min(x, len(heap))):
                count, num = heapq.heappop(heap)
                x_sums[i] += count * num

            if i == len(nums) - k:
                return x_sums

            window_counter[nums[i]] -= 1
            window_counter[nums[i + k]] += 1
