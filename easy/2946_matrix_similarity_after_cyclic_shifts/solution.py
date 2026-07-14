from typing import List


class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        rows = len(mat)
        cols = len(mat[0])

        k %= cols

        for row in range(rows):
            for col in range(cols):
                if mat[row][col] != mat[row][(col + k) % cols]:
                    return False

        return True
