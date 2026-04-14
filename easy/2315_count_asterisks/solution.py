class Solution:
    def countAsterisks(self, s: str) -> int:
        asterisks_count = 0
        in_pair = False

        for c in s:
            if c == "|":
                in_pair = not in_pair
            elif not in_pair and c == "*":
                asterisks_count += 1

        return asterisks_count
