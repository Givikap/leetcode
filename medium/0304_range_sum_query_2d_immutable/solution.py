from typing import List

class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.prefixSumsMatrix = []

        for row in matrix:
            self.prefixSumsMatrix.append([0])

            for num in row:
                self.prefixSumsMatrix[-1].append(self.prefixSumsMatrix[-1][-1] + num)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return sum([
            self.prefixSumsMatrix[row][col2 + 1] - self.prefixSumsMatrix[row][col1] 
            for row in range(row1, row2 + 1)
        ])