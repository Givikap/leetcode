from collections import Counter


class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        moves_counter = Counter(moves)
        return (
            abs(moves_counter["L"] - moves_counter["R"]) + moves_counter["_"]
        )
