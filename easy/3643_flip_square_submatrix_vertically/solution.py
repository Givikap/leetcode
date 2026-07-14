from typing import List


class Solution:
    def reverseSubmatrix(
        self, grid: List[List[int]], x: int, y: int, k: int
    ) -> List[List[int]]:
        for topRow, bottomRow in zip(
            range(x, x + k // 2), range(x + k - 1, -1, -1)
        ):
            for col in range(y, y + k):
                grid[topRow][col], grid[bottomRow][col] = (
                    grid[bottomRow][col],
                    grid[topRow][col],
                )

        return grid
