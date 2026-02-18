from collections import deque
from typing import List


class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        queue = deque((i, ticket) for i, ticket in enumerate(tickets))
        time = 0

        while queue:
            i, ticket = queue.popleft()

            time += 1
            ticket -= 1

            if ticket > 0:
                queue.append((i, ticket))
            elif i == k:
                break

        return time
