from collections import defaultdict
from typing import List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        loss_counter = defaultdict(int)

        for winner, loser in matches:
            loss_counter[winner]
            loss_counter[loser] += 1

        answer = [[], []]

        for loser in sorted(loss_counter.keys()):
            count = loss_counter[loser]

            if count < 2:
                answer[count].append(loser)

        return answer
