from typing import List


class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])

        k = k % (rows * cols)

        shifted_grid = [[0] * cols for _ in range(rows)]

        for i in range(rows * cols):
            shifted_grid[(i + k) // cols % rows][(i + k) % cols] = grid[
                i // cols
            ][i % cols]

        return shifted_grid
