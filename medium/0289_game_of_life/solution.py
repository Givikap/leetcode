from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        for row in range(len(board)):
            for col in range(len(board[0])):
                neighbors = [
                    (row + row_offset, col + col_offset)
                    for row_offset in (-1, 0, 1)
                    for col_offset in (-1, 0, 1)
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
                    if abs(board[r][c]) == 1:
                        live_neighbors_count += 1

                if board[row][col] == 1 and (
                    live_neighbors_count < 2 or live_neighbors_count > 3
                ):
                    board[row][col] = 2
                elif live_neighbors_count == 3:
                    board[row][col] = -1

        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == -1:
                    board[row][col] = 1
                elif board[row][col] == 2:
                    board[row][col] = 0
