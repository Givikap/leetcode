from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def _removeIsland(grid: List[List[str]], i: int, j: int) -> None:
            queue = [(i, j)]
            
            while len(queue) != 0:
                i, j = queue.pop()

                grid[j][i] = "0"

                if j + 1 < len(grid) and grid[j+1][i] == "1":
                    queue.append((i, j + 1))
                if i + 1 < len(grid[0]) and grid[j][i+1] == "1":
                    queue.append((i + 1, j))
                if j - 1 >= 0 and grid[j-1][i] == "1":
                    queue.append((i, j - 1))
                if i - 1 >= 0 and grid[j][i-1] == "1":
                    queue.append((i - 1, j))

        num_islands = 0

        for j in range(len(grid)):
            for i in range(len(grid[0])):
                if grid[j][i] == "1":
                    _removeIsland(grid, i, j)
                    num_islands += 1

        return num_islands