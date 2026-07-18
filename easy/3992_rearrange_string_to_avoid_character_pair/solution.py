from collections import Counter


class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        sCounter = Counter(s)

        t = []

        for _ in range(sCounter.get(y, 0)):
            t.append(y)

        sCounter.pop(y, 0)

        for c, count in sCounter.items():
            for _ in range(count):
                t.append(c)

        return "".join(t)
