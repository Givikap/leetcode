from typing import List

class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.prefixSumsMatrix = [[0] * (len(matrix[0]) + 1)]

        for row in matrix:
            self.prefixSumsMatrix.append([0])

            for i, num in enumerate(row):
                self.prefixSumsMatrix[-1].append(self.prefixSumsMatrix[-1][i] + num)

            for i in range(1, len(row) + 1):
                self.prefixSumsMatrix[-1][i] += self.prefixSumsMatrix[-2][i]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.prefixSumsMatrix[row2+1][col2+1] -
            self.prefixSumsMatrix[row2+1][col1] -
            self.prefixSumsMatrix[row1][col2+1] +
            self.prefixSumsMatrix[row1][col1]
        )