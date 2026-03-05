from typing import List


class Solution:
    def numSpecial(self, matrix: List[List[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])

        row_sums = []
        col_sums = [0] * cols

        for row in range(rows):
            row_sums.append(sum(matrix[row]))

            for col in range(cols):
                col_sums[col] += matrix[row][col]

        count = 0

        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == row_sums[row] == col_sums[col] == 1:
                    count += 1

        return count
