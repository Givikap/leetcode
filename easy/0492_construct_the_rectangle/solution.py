import math
from typing import List


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        rectangle = [area, 1]

        for side in range(2, int(math.sqrt(area)) + 1):
            if area % side == 0:
                rectangle = [area // side, side]

        return rectangle
