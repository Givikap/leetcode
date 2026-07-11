from typing import List

import numpy as np


class Solution:
    def pathExistenceQueries(
        self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]
    ) -> List[int]:
        items = sorted((num, i) for i, num in enumerate(nums))

        indicesMap = [0] * n
        for i in range(n):
            indicesMap[items[i][1]] = i

        reachable = [-1] * n
        for i in range(n - 2, -1, -1):
            if items[i + 1][0] - items[i][0] <= maxDiff:
                reachable[i] = reachable[i + 1]
            else:
                reachable[i] = i

        jumps = np.full((100001, 18), n - 1, dtype=np.int32)

        i = 0
        for j in range(n):
            while items[j][0] - items[i][0] > maxDiff:
                jumps[i][0] = j - 1
                i += 1

        while i < n:
            jumps[i][0] = n - 1
            i += 1

        for j in range(18):
            for i in range(n):
                jumps[i][j] = jumps[jumps[i][j - 1]][j - 1]

        pathsExist = [0] * len(queries)

        for i in range(len(queries)):
            u = queries[i][0]
            v = queries[i][1]

            if u != v:
                left = indicesMap[u]
                right = indicesMap[v]
                if left > right:
                    left, right = right, left

                if reachable[left] < right:
                    pathsExist[i] = -1
                else:
                    pathsExist[i] = 1

                    for j in range(17, -1, -1):
                        if jumps[left][j] < right:
                            left = jumps[left][j]
                            pathsExist[i] += 1 << j

        return pathsExist
