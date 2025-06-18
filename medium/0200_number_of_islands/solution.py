from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        num_islands = 0

        for j in range(len(grid)):
            for i in range(len(grid[0])):
                if grid[j][i] == "1":
                    queue = [(i, j)]
            
                    while len(queue) != 0:
                        ii, jj = queue.pop()

                        grid[jj][ii] = "0"

                        if jj + 1 < len(grid) and grid[jj+1][ii] == "1":
                            queue.append((ii, jj + 1))
                        if ii + 1 < len(grid[0]) and grid[jj][ii+1] == "1":
                            queue.append((ii + 1, jj))
                        if jj - 1 >= 0 and grid[jj-1][ii] == "1":
                            queue.append((ii, jj - 1))
                        if ii - 1 >= 0 and grid[jj][ii-1] == "1":
                            queue.append((ii - 1, jj))

                    num_islands += 1

        return num_islands
    
class CSolution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        num_islands = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    queue = [(r, c)]
            
                    while queue:
                        rr, cc = queue.pop()

                        grid[rr][cc] = "0"

                        if rr + 1 < rows and grid[rr+1][cc] == "1":
                            queue.append((rr + 1, cc))
                        if cc + 1 < cols and grid[rr][cc+1] == "1":
                            queue.append((rr, cc + 1))
                        if rr - 1 >= 0 and grid[rr-1][cc] == "1":
                            queue.append((rr - 1, cc))
                        if cc - 1 >= 0 and grid[rr][cc-1] == "1":
                            queue.append((rr, cc - 1))

                    num_islands += 1

        return num_islands