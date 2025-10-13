from typing import List


class Solution:
    def diagonalSum(self, matrix: List[List[int]]) -> int:
        return sum(
            matrix[i][i] + matrix[i][-1 - i] for i in range(len(matrix))
        ) - (
            matrix[len(matrix) // 2][len(matrix) // 2]
            if len(matrix) % 2 == 1
            else 0
        )
