class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        t = [y] * s.count(y)

        for c in s:
            if c != y:
                t.append(c)

        return "".join(t)
