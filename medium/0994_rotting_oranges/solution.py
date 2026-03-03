from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minutes = 0

        rotted = []
        to_rot = [
            (row, col)
            for row in range(len(grid))
            for col in range(len(grid[0]))
            if grid[row][col] == 2
        ]

        while to_rot:
            rotted.extend(to_rot)
            to_rot = []

            while rotted:
                row, col = rotted.pop()

                if row > 0 and grid[row - 1][col] == 1:
                    to_rot.append((row - 1, col))
                if col + 1 < len(grid[0]) and grid[row][col + 1] == 1:
                    to_rot.append((row, col + 1))
                if row + 1 < len(grid) and grid[row + 1][col] == 1:
                    to_rot.append((row + 1, col))
                if col > 0 and grid[row][col - 1] == 1:
                    to_rot.append((row, col - 1))

            if not to_rot:
                break

            to_rot = list(set(to_rot))
            for row, col in to_rot:
                grid[row][col] = 2

            minutes += 1

        for row in grid:
            if 1 in row:
                return -1

        return minutes
