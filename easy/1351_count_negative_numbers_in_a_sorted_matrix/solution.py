from typing import List


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        cols = len(grid[0])
        rows = len(grid)

        negatives_count = 0

        for row in range(rows):
            for col in range(cols - 1, -1, -1):
                if grid[row][col] >= 0:
                    break

                negatives_count += 1

        return negatives_count
