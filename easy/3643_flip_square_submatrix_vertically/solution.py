from typing import List


class Solution:
    def reverseSubmatrix(
        self, grid: List[List[int]], x: int, y: int, k: int
    ) -> List[List[int]]:
        topRow = x
        bottomRow = x + k - 1

        while topRow < bottomRow:
            for col in range(y, y + k):
                grid[topRow][col], grid[bottomRow][col] = (
                    grid[bottomRow][col],
                    grid[topRow][col],
                )

            topRow += 1
            bottomRow -= 1

        return grid
