from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        bits_counter_list = [0]
        offset = 1

        for i in range(1, n + 1):
            if offset * 2 == i:
                offset = i

            bits_counter_list.append(1 + bits_counter_list[i - offset])

        return bits_counter_list
