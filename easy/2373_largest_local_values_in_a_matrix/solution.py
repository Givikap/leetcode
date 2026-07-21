from typing import List


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)

        maxLocal = [[0] * (n - 2) for _ in range(n - 2)]

        for i in range(n - 2):
            for j in range(n - 2):
                currMax = 0

                for u in range(i, i + 3):
                    for v in range(j, j + 3):
                        currMax = max(currMax, grid[u][v])

                maxLocal[i][j] = currMax

        return maxLocal
