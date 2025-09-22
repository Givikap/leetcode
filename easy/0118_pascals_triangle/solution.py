from typing import List


class Solution:
    def generate(self, num_rows: int) -> List[List[int]]:
        rows = [[1]]

        if num_rows > 1:
            rows.append([1, 1])

        for _ in range(num_rows - 2):
            row = [1]

            for i in range(len(rows[-1]) - 1):
                row.append(rows[-1][i] + rows[-1][i + 1])

            row.append(1)
            rows.append(row)

        return rows
