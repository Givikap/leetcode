import heapq
from collections import Counter, deque
from typing import List


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        window = deque(nums[:k])
        x_sums = []

        for i in range(len(nums) - k + 1):
            window_counter = Counter(window)

            heap = [
                (-window_counter[num], -num, num) for num in window_counter
            ]
            heapq.heapify(heap)

            x_sum = 0

            for _ in range(min(x, len(window_counter))):
                num = heapq.heappop(heap)[2]
                x_sum += num * window_counter[num]

            x_sums.append(x_sum)

            window.popleft()
            if k + i < len(nums):
                window.append(nums[k + i])

        return x_sums
