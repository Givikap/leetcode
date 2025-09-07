from typing import List


class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        winners = [False] * n

        curr = 0
        turn = 1

        while True:
            if winners[curr]:
                break

            winners[curr] = True

            curr = (curr + k * turn) % n
            turn += 1

        return [i + 1 for i, is_winner in enumerate(winners) if not is_winner]
