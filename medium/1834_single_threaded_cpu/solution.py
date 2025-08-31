import heapq
from collections import deque
from typing import List


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tasks = deque(sorted([(*task, i) for i, task in enumerate(tasks)]))

        time = tasks[0][0]
        available = []

        order = []

        while tasks or available:
            if not available and time < tasks[0][0]:
                time = tasks[0][0]

            while tasks and tasks[0][0] <= time:
                heapq.heappush(available, tasks.popleft()[1:])

            if available:
                processingTime, i = heapq.heappop(available)

                time += processingTime
                order.append(i)

        return order
