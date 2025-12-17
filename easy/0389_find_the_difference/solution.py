from collections import Counter


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_counter = Counter(s)

        for c in t:
            if c in s_counter:
                s_counter[c] -= 1

                if s_counter[c] < 0:
                    return c
            else:
                return c
