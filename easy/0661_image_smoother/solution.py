from typing import List


class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        rows = len(img)
        cols = len(img[0])

        offsets = [
            (-1, -1),
            (0, -1),
            (1, -1),
            (-1, 0),
            (0, 0),
            (1, 0),
            (-1, 1),
            (0, 1),
            (1, 1),
        ]

        imgSmoothed = [[0] * cols for _ in range(rows)]

        for row in range(rows):
            for col in range(cols):
                cells = []

                for rowOffset, colOffset in offsets:
                    if (
                        0 <= row + rowOffset < rows
                        and 0 <= col + colOffset < cols
                    ):
                        cells.append(img[row + rowOffset][col + colOffset])

                imgSmoothed[row][col] = sum(cells) // len(cells)

        return imgSmoothed
