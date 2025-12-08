import math


class Solution:
    def countTriples(self, n: int) -> int:
        triples_count = 0

        for a in range(1, n + 1):
            for b in range(1, n + 1):
                c = math.sqrt(a * a + b * b)

                if c.is_integer() and c <= n:
                    triples_count += 1

        return triples_count
