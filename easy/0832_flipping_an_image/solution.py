from typing import List


class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        return [[int(not bool(cell)) for cell in row[::-1]] for row in image]
