import heapq
from typing import List

class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        order = []

        tasks = [[*task, i] for i, task in enumerate(tasks)]
        heapq.heapify(tasks)

        time = tasks[0][0]
        available = []

        while tasks or available:
            while tasks and tasks[0][0] <= time:
                heapq.heappush(available, heapq.heappop(tasks)[1:])

            if available:
                processingTime, i = heapq.heappop(available)

                order.append(i)
                time += processingTime
            else:
                time = tasks[0][0]

        return order