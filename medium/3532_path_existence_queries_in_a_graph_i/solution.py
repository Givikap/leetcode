from typing import List


class Solution:
    def pathExistenceQueries(
        self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]
    ) -> List[bool]:
        groupsMap = [0] * n
        currGroup = 0

        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff:
                currGroup += 1

            groupsMap[i] = currGroup

        return [groupsMap[i] == groupsMap[j] for i, j in queries]
