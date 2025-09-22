from copy import deepcopy
from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        board_copy = deepcopy(board)

        for row in range(len(board)):
            for col in range(len(board[0])):
                neighbors = [
                    (row + row_offset, col + col_offset)
                    for row_offset in (-1, 0, 1)
                    for col_offset in (-1, 0, 1)
                    if not (
                        row + row_offset == row and col + col_offset == col
                    )
                ]

                neighbors = [
                    (r, c)
                    for r, c in neighbors
                    if 0 <= r < len(board)
                    and 0 <= c < len(board[0])
                    and not (r == row and c == col)
                ]

                live_neighbors_count = 0

                for r, c in neighbors:
                    if board_copy[r][c]:
                        live_neighbors_count += 1

                if board[row][col]:
                    if live_neighbors_count < 2 or live_neighbors_count > 3:
                        board[row][col] = 0
                elif live_neighbors_count == 3:
                    board[row][col] = 1
