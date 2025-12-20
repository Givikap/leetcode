from typing import List


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        delete_count = 0

        cols = len(strs[0])
        rows = len(strs) - 1

        for col in range(cols):
            for row in range(rows):
                if strs[row][col] > strs[row + 1][col]:
                    delete_count += 1
                    break

        return delete_count
