from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        length = len(matrix)
        width = len(matrix[0])

        i = j = 0

        while i < length or j < width:
            if matrix[i][j] == target:
                return True

            if j + 1 < width and matrix[i][j+1] <= target:
                j += 1
            elif i + 1 < length and matrix[i+1][j] <= target:
                i += 1
            elif i + 1 < length:
                i += 1
                j = 0
            else:
                break

        return False