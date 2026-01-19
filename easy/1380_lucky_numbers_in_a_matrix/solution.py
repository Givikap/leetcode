from typing import List


class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        cols = len(matrix[0])

        min_num_by_row = [0] * rows
        max_num_by_col = [0] * cols

        for row in range(rows):
            min_num_by_row[row] = min(matrix[row])

        for col in range(cols):
            max_num_by_col[col] = max(matrix[row][col] for row in range(rows))

        lucky_nums = []

        for row in range(rows):
            for col in range(cols):
                if min_num_by_row[row] == max_num_by_col[col]:
                    lucky_nums.append(matrix[row][col])

        return lucky_nums
