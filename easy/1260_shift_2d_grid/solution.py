from typing import List


class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])

        size = rows * cols
        shift = size - (k % (size))

        flatten_grid = []

        for row in grid:
            flatten_grid.extend(row)

        flatten_grid = [*flatten_grid[shift:], *flatten_grid[:shift]]

        return [flatten_grid[i : i + cols] for i in range(0, size, cols)]
