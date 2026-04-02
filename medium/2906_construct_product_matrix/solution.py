from typing import List


class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])

        product_grid = [[1] * cols for _ in range(rows)]

        matrix_product = 1

        for row in range(rows):
            for col in range(cols):
                matrix_product *= grid[row][col]

        for row in range(rows):
            for col in range(cols):
                product_grid[row][col] = (
                    matrix_product // grid[row][col]
                ) % 12345

        return product_grid
