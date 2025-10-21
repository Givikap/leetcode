from typing import List


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_map = {c: i for i, c in zip(range(97, 123), order)}

        for i in range(len(words) - 1):
            for j in range(min(len(words[i]), len(words[i + 1]))):
                if order_map[words[i][j]] < order_map[words[i + 1][j]]:
                    break
                elif order_map[words[i][j]] > order_map[words[i + 1][j]]:
                    return False

            if order_map[words[i][j]] == order_map[words[i + 1][j]] and len(
                words[i]
            ) > len(words[i + 1]):
                return False

        return True
