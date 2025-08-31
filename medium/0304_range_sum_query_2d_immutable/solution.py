from typing import List


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        cols = len(matrix[0])

        self.prefixSumsMatrix = [[0] * (cols + 1) for _ in range(rows + 1)]

        for row in range(1, rows + 1):
            for col in range(1, cols + 1):
                self.prefixSumsMatrix[row][col] = (
                    matrix[row - 1][col - 1]
                    + self.prefixSumsMatrix[row - 1][col]
                    + self.prefixSumsMatrix[row][col - 1]
                    - self.prefixSumsMatrix[row - 1][col - 1]
                )

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.prefixSumsMatrix[row2 + 1][col2 + 1]
            - self.prefixSumsMatrix[row2 + 1][col1]
            - self.prefixSumsMatrix[row1][col2 + 1]
            + self.prefixSumsMatrix[row1][col1]
        )
