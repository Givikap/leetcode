class Solution:
    def numberOfMatches(self, n: int) -> int:
        matches_count = 0

        while n > 1:
            matches_count += n // 2

            if n % 2 == 1:
                n += 1

            n //= 2

        return matches_count
