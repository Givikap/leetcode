class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left_count = right_count = blank_count = 0

        for move in moves:
            if move == "L":
                left_count += 1
            elif move == "R":
                right_count += 1
            else:
                blank_count += 1

        return abs(left_count - right_count) + blank_count
