from typing import List

from utils.python import UnionFind


class Solution:
    def pathExistenceQueries(
        self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]
    ) -> List[bool]:
        uf = UnionFind(n)

        for i in range(1, n):
            if nums[i] - nums[i - 1] <= maxDiff:
                uf.union(i, i - 1)

        return [uf.find(i) == uf.find(j) for i, j in queries]
