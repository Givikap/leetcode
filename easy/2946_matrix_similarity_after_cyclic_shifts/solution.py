from copy import deepcopy
from typing import List


class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        rows = len(mat)
        cols = len(mat[0])

        k %= cols

        matCopy = deepcopy(mat)

        for row in range(rows):
            for col in range(cols):
                if row % 2 == 0:
                    matCopy[row][col] = mat[row][col - k]
                else:
                    matCopy[row][col] = mat[row][(col + k) % cols]

        return matCopy == mat
