from collections import Counter


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_counter = Counter(s)
        t_counter = Counter(t)

        for c in t_counter:
            if c not in s_counter or s_counter[c] != t_counter[c]:
                return c
