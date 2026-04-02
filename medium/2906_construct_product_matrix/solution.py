from typing import List


class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])

        product_grid = []
        for _ in range(rows):
            product_grid.append([1] * cols)

        for r1 in range(rows):
            for c1 in range(cols):
                for r2 in range(rows):
                    for c2 in range(cols):
                        product_grid[r1][c1] *= grid[r2][c2]

                product_grid[r1][c1] = (
                    product_grid[r1][c1] // grid[r1][c1]
                ) % 12345

        return product_grid
