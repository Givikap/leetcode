import heapq
from typing import List


class Solution:
    def findRelativeRanks(self, scores: List[int]) -> List[str]:
        heap = [(-score, i) for i, score in enumerate(scores)]
        heapq.heapify(heap)

        podium = ["Gold Medal", "Silver Medal", "Bronze Medal"]

        ranks = [""] * len(scores)
        rank = 1

        while heap:
            _, i = heapq.heappop(heap)

            ranks[i] = podium[rank - 1] if rank < 4 else str(rank)
            rank += 1

        return ranks
