import heapq
from typing import List


class Solution:
    def findRelativeRanks(self, scores: List[int]) -> List[str]:
        podium = ["Bronze Medal", "Silver Medal", "Gold Medal"]

        scores = [(-score, i) for i, score in enumerate(scores)]
        heapq.heapify(scores)

        ranks = [""] * len(scores)

        pos = 0

        while scores:
            _, i = heapq.heappop(scores)
            pos += 1

            if podium:
                rank = podium.pop()
            else:
                rank = str(pos)

            ranks[i] = rank

        return ranks
