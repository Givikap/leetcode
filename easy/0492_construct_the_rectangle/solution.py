import math
from typing import List


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        for side in range(int(math.sqrt(area)), 0, -1):
            if area % side == 0:
                return [area // side, side]

        return [area, 1]
